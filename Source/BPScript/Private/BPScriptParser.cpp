
#include "CoreMinimal.h"

#include "BPScriptParser.h"
#include "Logging/LogMacros.h"


struct BPTransition
{
	TokenType type;
	std::string value;
	int target_state;
};

std::vector<std::vector<struct BPTransition>> STATE_TRANSITIONS = {
	// State 0: No Class
	{ { TokenType::Identifier, "", 1 } },
	// State 1: Have Class Name
	{ { TokenType::Symbol, ":", 2 } },
	// State 2: Have Class Name, Getting Parent
	{ { TokenType::Identifier, "", 3 } },
	// State 3: Have Class and Parent Names
	{ { TokenType::Symbol, "|", 4 },{ TokenType::Symbol, "{", 6 } },
	// State 4: Waiting for Interface
	{ { TokenType::Identifier, "", 5 } },
	// State 5: Got Interface
	{ { TokenType::Symbol, ",", 4 },{ TokenType::Symbol, "{", 6 } },
	// State 6: Header parsed, now for the body
	{}
};

bool State0(BPScriptParser* Parser, struct Token* Tok)
{
	if (Parser->CurrentClass)
	{
		Parser->Classes.push_back(Parser->CurrentClass);
		Parser->CurrentClass = nullptr;
	}
	return true;
}

bool State1(BPScriptParser* Parser, struct Token* Tok)
{
	Parser->CurrentClass = new BPScriptClass();
	Parser->CurrentClass->ClassName = Tok->val;
	return true;
}

bool State3(BPScriptParser* Parser, struct Token* Tok)
{
	Parser->CurrentClass->Parent = Tok->val;
	return true;
}

bool State5(BPScriptParser* Parser, struct Token* Tok)
{
	Parser->CurrentClass->Interfaces.push_back(Tok->val);
	return true;
}

bool (*STATE_FUNCTIONS[])(BPScriptParser*, struct Token*) = {
	State0, State1, nullptr, State3, nullptr, State5, nullptr
};

// Returns whether transition was a success.
bool TryTransition(BPScriptParser* Parser, Token* tok)
{
	// Look through the transitions
	for (BPTransition t : STATE_TRANSITIONS[Parser->CurrentState])
	{
		// If the types match, and the values match (assuming the type is one
		// where value matters), then we will transition.
		if (t.type == tok->type && (t.type == TokenType::Identifier
			|| t.type == TokenType::Number || t.type == TokenType::String
			|| t.value == tok->val))
		{
			// Change the current state.
			Parser->CurrentState = t.target_state;
			// If the state function is valid, run it.
			if (STATE_FUNCTIONS[Parser->CurrentState] != nullptr)
			{
				// Run the state function. The success of this function
				// determines transition success.
				return STATE_FUNCTIONS[Parser->CurrentState](Parser, tok);
			}
			else
			{
				// Otherwise, just accept the transition.
				return true;
			}
		}
	}
	// If we got through all transitions without finding a valid one, then
	// the transition failed.
	return false;
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
				}
				UE_LOG(BPScript, Display, TEXT("Class: %s"), *FString(std::string(*CurrentClass).c_str()));
				delete tok;
				fclose(token_file);
				fclose(read_file);
				return BAD_SCRIPT;
			}
		}
		//UE_LOG(BPScript, Display, TEXT("Token Type: %s\t\"%s\""), *enumToTokens[(int)tok->type], *FString(tok->val.c_str()));
		delete tok;
	}

	fclose(token_file);
	fclose(read_file);
	return SUCCESS;
}
