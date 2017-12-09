
#pragma once

#include <cstdio>
#include <string>

#define TOKENIZER_BUFFER_SIZE 1024

enum TokenType { Whitespace = 0, Identifier, Keyword, Symbol, Number, Comment, String };

struct TokenBounds
{
	TokenType type;
	long start;
	long end;
};

struct Token
{
	TokenType type;
	std::string val;
};

struct TokenBounds* Tokenize(char* buf, int& buf_size, int& start_pos, std::FILE* file);

struct Token* ReadTokenFromBounds(struct TokenBounds* bounds, std::FILE* file);
