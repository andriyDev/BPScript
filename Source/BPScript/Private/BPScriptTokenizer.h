
#pragma once

#include <cstdio>
#include <string>

#define TOKENIZER_BUFFER_SIZE 1024

enum TokenType { Whitespace = 0, Identifier, Keyword, Symbol, Number, Comment, String };

struct Token
{
	TokenType type;
	long start;
	long end;
	std::string val;
};

struct Token* Tokenize(char* buf, int& buf_size, int& start_pos, std::FILE* token_file, std::FILE* read_file);
