
#include "CoreMinimal.h"

#include "BPScriptParser.h"
#include "Logging/LogMacros.h"

void EmptyPastTokens(BPScriptParser* Parser)
{
	for (struct Token* del_tok : Parser->PastTokens)
	{
		if (del_tok)
		{
			delete del_tok;
		}
	}
	Parser->PastTokens.clear();
}

TokenType CharToToken(char c)
{
	char val = 0;
	if (c > 90)
	{
		c -= 32;
		val += 28;
	}
	val += c - 63;
	return (TokenType)val;
}

char TokenToChar(TokenType token)
{
	char tok_val = (char)token;
	char val = 63;
	if (tok_val < 28)
	{
		val += tok_val;
	}
	else
	{
		val += 32 + tok_val;
	}
	return val;
}

int BPScriptParser::ReadScript(std::string filename)
{
	// Setup a read buffer
	char buf[TOKENIZER_BUFFER_SIZE];
	int buf_size = 0;
	int start_pos = 0;
	buf[0] = '\0';

	// Open the script file. This file will be used to tokenize the script
	std::FILE* token_file;
	if (fopen_s(&token_file, filename.c_str(), "rb") != 0)
	{
		UE_LOG(BPScript, Display, TEXT("Could not open script file!"));
		return BAD_FILE;
	}
	// Open the script file. This file will be used to read the tokens
	std::FILE* read_file;
	if (fopen_s(&read_file, filename.c_str(), "rb") != 0)
	{
		UE_LOG(BPScript, Display, TEXT("Could not open script file!"));
		return BAD_FILE;
	}

	// Setup a mapping from enum to strings
	FString enumToTokens[] = { "Whitespace", "Identifier", "Keyword", "Symbol", "Number", "Comment", "String" };

	// Keep tokenizing until there is no token.
	struct Token* tok;
	while ((tok = Tokenize(buf, buf_size, start_pos, token_file, read_file)) != nullptr)
	{
		// Make sure this isn't a type to ignore
		if (tok->type != TokenType::Whitespace && tok->type != TokenType::Comment)
		{
			if (!TryTransition(this, tok))
			{
				for (BPScriptClass* c : Classes)
				{
					UE_LOG(BPScript, Display, TEXT("Class: %s"), *FString(std::string(*c).c_str()));
					delete c;
				}
				Classes.clear();
				UE_LOG(BPScript, Display, TEXT("Class: %s"), *FString(std::string(*CurrentClass).c_str()));

				delete CurrentClass;
				CurrentClass = nullptr;

				UE_LOG(BPScript, Display, TEXT("Failed on token: %s"), *FString(tok->val.c_str()));
				delete tok;
				fclose(token_file);
				fclose(read_file);
				return BAD_SCRIPT;
			}
		}
		delete tok;
	}

	fclose(token_file);
	fclose(read_file);
	return SUCCESS;
}
