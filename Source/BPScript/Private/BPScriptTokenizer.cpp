
#include "CoreMinimal.h"

#include "BPScriptTokenizer.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// === LANGUAGE KEYWORDS === //

// "Primitive" Data Types
#define DT_FLOAT "float"
#define DT_INTEGER "int"
#define DT_BOOLEAN "bool"
#define DT_BYTE "byte"
#define DT_NAME "name"
#define DT_STRING "string"
#define DT_TEXT "text"

// Property Modifiers
#define PM_CAT "Category"
#define PM_IE "InstanceEditable"
#define PM_TT "Tooltip"
#define PM_BPRO "BlueprintReadOnly"
#define PM_EOS "ExposeOnSpawn"
#define PM_PRIV "Private"
#define PM_REP "Replication"
#define PM_REPCON "RepCondition"
#define PM_ETC "ExposeToCinematics"
#define PM_SR "SliderRange"
#define PM_VR "ValueRange"

// Special Values
#define SV_T "true"
#define SV_F "false"
#define SV_0 "None"

// === === //

#define KEYWORD_COUNT 21
char* KEYWORD_ARR[KEYWORD_COUNT] = {
	// Primitive Data Types
	DT_FLOAT, DT_INTEGER, DT_BOOLEAN, DT_BYTE, DT_NAME, DT_STRING, DT_TEXT,
	// Property Modifiers
	PM_CAT, PM_IE, PM_TT, PM_BPRO, PM_EOS, PM_PRIV, PM_REP, PM_REPCON, PM_ETC, PM_SR, PM_VR,
	// Special Values
	SV_T, SV_F, SV_0
};

void ReadToBuffer(char* buf, int& buf_size, std::FILE* file)
{
	buf_size += fread(&buf[buf_size], sizeof(char), TOKENIZER_BUFFER_SIZE - 1 - buf_size, file);
	buf[buf_size] = '\0';
}

void ConsumeBytes(char* buf, int& buf_size, int& start_pos, int bytes_to_consume)
{
	if (bytes_to_consume == 0)
	{
		return;
	}

	char* str = new char[bytes_to_consume + 1];
	memcpy(str, buf, bytes_to_consume);
	str[bytes_to_consume] = '\0';
	delete str;

	start_pos += bytes_to_consume;
	buf_size -= bytes_to_consume;
	memcpy(buf, &buf[bytes_to_consume], buf_size);
	buf[buf_size] = '\0';
}

int ReadRemainingToken(char* buf, int& buf_size, int& start_pos, std::FILE* file, int(*is_char)(int))
{
	ReadToBuffer(buf, buf_size, file);
	while (buf_size != 0)
	{
		for (int i = 0; i < buf_size; i++)
		{
			if (!is_char(buf[i]))
			{
				ConsumeBytes(buf, buf_size, start_pos, i);
				return start_pos;
			}
		}
		ConsumeBytes(buf, buf_size, start_pos, buf_size);
		ReadToBuffer(buf, buf_size, file);
	}
	return start_pos;
}

int EnsureBufferSize(char* buf, int& buf_size, std::FILE* file, int expected_size)
{
	if (buf_size < expected_size)
	{
		ReadToBuffer(buf, buf_size, file);
		return buf_size >= expected_size;
	}
	else
	{
		return true;
	}
}

int is_non_quote_or_escape(int c)
{
	return c != '\\' && c != '\"';
}

int isnotnewline(int c)
{
	return c != '\n';
}

int isnotstar(int c)
{
	return c != '*';
}

int isalphanumericorunderscore(int c)
{
	return isalnum(c) || c == '_';
}

struct TokenBounds* Tokenize(char* buf, int& buf_size, int& start_pos, std::FILE* file)
{
	// Make sure we have at least one character to tokenize.
	if (!EnsureBufferSize(buf, buf_size, file, 1))
	{
		return nullptr;
	}

	// Create a new token and set it's starting position.
	struct TokenBounds* new_token = new struct TokenBounds;
	new_token->start = start_pos;

	// Is whitespace?
	if (isspace(buf[0]))
	{
		// We will read all the whitespace we can and return the token.
		ConsumeBytes(buf, buf_size, start_pos, 1);
		new_token->type = TokenType::Whitespace;

		new_token->end = ReadRemainingToken(buf, buf_size, start_pos, file,
			isspace);
		return new_token;
	}
	// Is string?
	else if (buf[0] == '\"')
	{
		new_token->type = TokenType::String;
		while (true)
		{
			// Consume the first character. First iter will be ". Otherwise,
			// will be an escaped character.
			ConsumeBytes(buf, buf_size, start_pos, 1);
			// Read any character, until we hit either a \ or a "
			ReadRemainingToken(buf, buf_size, start_pos, file,
				is_non_quote_or_escape);
			// Make sure we have at least one character to check for end of
			// string
			if (!EnsureBufferSize(buf, buf_size, file, 1))
			{
				// If there is no character, we have a run-on string. Just
				// return null.
				delete new_token;
				return nullptr;
			}

			if (buf[0] == '"')
			{
				// Consume the last quote.
				ConsumeBytes(buf, buf_size, start_pos, 1);
				new_token->end = start_pos;
				return new_token;
			}
			else
			{
				// Consume the \ character
				ConsumeBytes(buf, buf_size, start_pos, 1);
				// Make sure there is at least one character for the next
				// iteration.
				if (!EnsureBufferSize(buf, buf_size, file, 1))
				{
					// If there is no character, escape character is missing.
					// Just return null.
					delete new_token;
					return nullptr;
				}
			}
		}
	}
	// Is comment or division?
	else if (buf[0] == '/')
	{
		ConsumeBytes(buf, buf_size, start_pos, 1);
		if (!EnsureBufferSize(buf, buf_size, file, 1))
		{
			// If there is no character, this is unrecoverable... just
			// return null.
			delete new_token;
			return nullptr;
		}
		// Is it a line comment?
		if (buf[0] == '/')
		{
			// Consume it!
			new_token->type = TokenType::Comment;
			new_token->end = ReadRemainingToken(buf, buf_size, start_pos, file,
				isnotnewline);
			return new_token;
		}
		// Is it a block comment?
		else if (buf[0] == '*')
		{
			new_token->type = TokenType::Comment;
			while (true)
			{
				// Consume the star.
				ConsumeBytes(buf, buf_size, start_pos, 1);
				// Read until we get a star.
				ReadRemainingToken(buf, buf_size, start_pos, file, isnotstar);
				if (!EnsureBufferSize(buf, buf_size, file, 2))
				{
					// If there is no character, it is a run-on comment. Just
					// return null.
					delete new_token;
					return nullptr;
				}
				// If the character following the star is a slash, end the
				// block comment.
				if (buf[1] == '/')
				{
					ConsumeBytes(buf, buf_size, start_pos, 2);
					new_token->end = start_pos;
					return new_token;
				}
				// Otherwise, try again.
			}
		}
		// Then it must be division!
		else
		{
			new_token->type = TokenType::Symbol;
			new_token->end = start_pos;
			return new_token;
		}
	}
	// Is keyword or identifier
	else if (isalpha(buf[0]) || buf[0] == '_')
	{
		// Fill the buffer as much as we can.
		ReadToBuffer(buf, buf_size, file);

		// Go through the buffer, find the first character that isn't a part
		// of the identifier. End the token there.
		int tok_len;
		for (tok_len = 1; tok_len < buf_size; tok_len++)
		{
			if (!isalphanumericorunderscore(buf[tok_len]))
			{
				new_token->end = start_pos + tok_len;
				break;
			}
		}

		// Go through all the keywords. Look for any that match.
		for (int i = 0; i < KEYWORD_COUNT; i++)
		{
			// Comparing strings by hand instead of using strcmp for efficiency
			if (strlen(KEYWORD_ARR[i]) == tok_len)
			{
				int j;
				for (j = 0; j < tok_len; j++)
				{
					if (KEYWORD_ARR[i][j] != buf[j])
					{
						break;
					}
				}
				// If we didn't break early, all characters are the same!
				if (j == tok_len)
				{
					// This is a keyword!
					new_token->type = TokenType::Keyword;
					ConsumeBytes(buf, buf_size, start_pos, tok_len);
					return new_token;
				}
			}
		}

		ConsumeBytes(buf, buf_size, start_pos, tok_len);
		new_token->type = TokenType::Identifier;
		return new_token;
	}
	// Is a dot or a number?
	else if (isdigit(buf[0]) || buf[0] == '.')
	{
		// The token could be either the dot operator OR a number, so we have
		// to check
		if (buf[0] == '.')
		{
			// Make sure there is a character after the dot.
			if (!EnsureBufferSize(buf, buf_size, file, 2))
			{
				// If the buffer isn't big enough, that means we hit
				// an error or EOF, so there is nothing after the dot. Just
				// send the token.
				ConsumeBytes(buf, buf_size, start_pos, 1);
				new_token->type = TokenType::Symbol;
				new_token->end = start_pos;
				return new_token;
			}
			// If we got here, the buffer is big enough. If the next character
			// is not a number, that means this token is a dot.
			if (!isdigit(buf[1]))
			{
				ConsumeBytes(buf, buf_size, start_pos, 1);
				new_token->type = TokenType::Symbol;
				new_token->end = start_pos;
				return new_token;
			}
		}
		// If we got here, the token isn't a dot, so it must be anumber
		new_token->type = TokenType::Number;

		// Read as many digits as we can.
		ReadRemainingToken(buf, buf_size, start_pos, file, isdigit);
		// If there are no more characters, just end the number. Otherwise, we
		// need to test the number for a decimal.
		if (!EnsureBufferSize(buf, buf_size, file, 1))
		{
			new_token->end = start_pos;
			return new_token;
		}
		if (buf[0] == '.')
		{
			// Consume the dot.
			ConsumeBytes(buf, buf_size, start_pos, 1);
			// Read as many digits as we can.
			new_token->end = ReadRemainingToken(buf, buf_size, start_pos, file, isdigit);
			return new_token;
		}
		else
		{
			// Whatever else is after here, we will ignore. The number is done.
			new_token->end = start_pos;
			return new_token;
		}
	}
	// Otherwise, it must be a symbol with no ambiguity
	else
	{
		if (!strchr(",{}[]<>+-*&|$#;:=!%^", buf[0]))
		{
			// If it isn't a symbol, this is an unrecognized token. Kill it.
			ConsumeBytes(buf, buf_size, start_pos, 1);
			delete new_token;
			return nullptr;
		}
		// It is a symbol! Consume it!
		ConsumeBytes(buf, buf_size, start_pos, 1);
		new_token->type = TokenType::Symbol;
		new_token->end = start_pos;
		return new_token;
	}
}

struct Token* ReadTokenFromBounds(struct TokenBounds* bounds, std::FILE* file)
{
	char* str = new char[bounds->end - bounds->start + 1];
	fseek(file, bounds->start, SEEK_SET);
	fread(str, 1, bounds->end - bounds->start, file);
	str[bounds->end - bounds->start] = '\0';

	struct Token* tok = new struct Token;
	tok->type = bounds->type;
	tok->val = str;

	delete str;
	return tok;
}
