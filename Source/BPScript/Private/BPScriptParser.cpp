
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
	// State 0
	{ { TokenType::Identifier, "", 1 } },
	// State 1
	{ { TokenType::Symbol, ":", 2 } },
	// State 2
	{ { TokenType::Identifier, "", 3 } },
	// State 3
	{ { TokenType::Symbol, "|", 4 },{ TokenType::Symbol, "{", 6 } },
	// State 4
	{ { TokenType::Identifier, "", 5 } },
	// State 5
	{ { TokenType::Symbol, ",", 4 },{ TokenType::Symbol, "{", 6 } },
	// State 6
	{}
};

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
		return 1;
	}
	// Open the script file. This file will be used to read the tokens
	std::FILE* read_file;
	if (fopen_s(&read_file, filename.c_str(), "rb") != 0)
	{
		UE_LOG(BPScript, Display, TEXT("Could not open script file!"));
		return 1;
	}

	// Setup a mapping from enum to strings
	FString enumToTokens[] = { "Whitespace", "Identifier", "Keyword", "Symbol", "Number", "Comment", "String" };

	// Keep tokenizing until there is no token.
	struct Token* tok;
	while ((tok = ReadTokenFromBounds(Tokenize(buf, buf_size, start_pos, token_file), read_file)) != nullptr)
	{
		UE_LOG(BPScript, Display, TEXT("Token Type: %s\t\"%s\""), *enumToTokens[(int)tok->type], *FString(tok->val.c_str()));
		delete tok;
	}

	return 0;
}
