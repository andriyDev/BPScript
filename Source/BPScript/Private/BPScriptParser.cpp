
#include "CoreMinimal.h"

#include "BPScriptParser.h"
#include <stdio.h>
#include "BPScriptTokenizer.h"

#include "Logging/LogMacros.h"

std::FILE* token_file;
std::FILE* read_file;

int yylex()
{
	char buf[TOKENIZER_BUFFER_SIZE];
	int buf_size;
	int start_pos;

	struct Token* tok = Tokenize(buf, buf_size, start_pos, token_file, read_file);
}

static void print_token_value(std::FILE* f, int pos, YYSTYPE type)
{
	UE_LOG(BPScript, Display, TEXT("TokenValue: %d"), pos);
}

void ParseScript(const char* filename)
{
	token_file = fopen(filename, "r");
	read_file = fopen(filename, "r");
	if (!token_file || !read_file)
	{
		UE_LOG(BPScript, Error, TEXT("Failed to open target file for read: %s"), UTF8_TO_TCHAR(filename));
	}

	fclose(token_file);
	fclose(read_file);

	token_file = nullptr;
	read_file = nullptr;
}
