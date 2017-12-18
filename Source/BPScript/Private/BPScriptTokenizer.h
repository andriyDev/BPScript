
#pragma once

#include <cstdio>
#include <string>
#include "BPScriptParserCore.h"

#define TOKENIZER_BUFFER_SIZE 1024

enum TokenType { Whitespace = 0, Identifier, Symbol, Number, Comment,
	String, Primitive, Dispatcher, Event, Defaults, Construction, Function,
	Macro, Collapsed, Ref, Exec, LogicalAnd, LogicalOr, GTE, LTE, Eq, Neq, If,
	Else, Var, For, ForEach, While, Break, Return, End, Local, True, False, None };

struct Token
{
	TokenType type;
	long start;
	long end;
	std::string val;
};

struct Token* Tokenize(char* buf, int& buf_size, int& start_pos, std::FILE* token_file, std::FILE* read_file);
