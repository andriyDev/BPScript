
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
	{ { TokenType::Identifier, "", 7 }, { TokenType::PrimitiveDT, "", 15 } },

	// === Variable Parsing === //
	// State 7: Identifier of variable found, needs reference type.
	{ { TokenType::Symbol, "$", 8 }, { TokenType::Symbol, "&", 8 },
	{ TokenType::Symbol, "*", 8 }, { TokenType::Symbol, "#", 8 } },
	// State 8: Variable Reference Type Found.
	{ { TokenType::Symbol, "[", 9 }, { TokenType::Symbol, "{", 11 },
	{ TokenType::Symbol, ":", 12 }, { TokenType::Identifier, "", 16 } },
	// State 9: Variable Array started!
	{ { TokenType::Symbol, "]", 14 } },
	// State 10: Struct Started
	{ { TokenType::Symbol, "{", 11 }, { TokenType::Symbol, "[", 9 },
	{ TokenType::Symbol, ":", 12 }, { TokenType::Identifier, "", 16 } },
	// State 11: Variable Set started!
	{ { TokenType::Symbol, "}", 14 } },
	// State 12: Starting a Dictionary!
	{ { TokenType::PrimitiveDT, "", 14 }, { TokenType::Identifier, "", 13 } },
	// State 13: Identifier of value var found, needs reference type.
	{ { TokenType::Symbol, "$", 14 }, { TokenType::Symbol, "&", 14 },
	{ TokenType::Symbol, "*", 14 },{ TokenType::Symbol, "#", 14 } },
	// State 14: Have variable type, need identifier
	{ { TokenType::Identifier, "", 16 } },
	// State 15: Have Primitive first variable
	{ { TokenType::Symbol, "[", 9 }, { TokenType::Symbol, "{", 11 },
	{ TokenType::Symbol, ":", 12 }, { TokenType::Identifier, "", 16 } },
	// State 16: Have completely formed variable!
	{ { TokenType::Symbol, "<", 17 } },

	// === Property Modifier Parsing === //
	// State 17: Reading variable property modifier
	{ { TokenType::PropertyModifier, "", 18 } },
	// State 18: Got a property modifier
	{ { TokenType::Symbol, ",", 17 }, { TokenType::Symbol, ":", 19 } },
	// State 19: Reading property modifier value
	{ { TokenType::String, "", 20 }, { TokenType::Number, "", 20 },
	{ TokenType::Keyword, "true", 20 }, { TokenType::Keyword, "false", 20 },
	{ TokenType::Identifier, "", 20 }, { TokenType::Symbol, "{", 22 },
	{ TokenType::Symbol, "-", 26 } },
	// State 20: Got Property modifier value
	{ { TokenType::Symbol, ",", 17 }, { TokenType::Symbol, ">", 21 } },
	// State 21: Finished property modifiers
	{  },
	// State 22: Starting property modifier range
	{ { TokenType::Number, "", 23 }, { TokenType::Symbol, "-", 27 } },
	// State 23: Have first value of range
	{ { TokenType::Symbol, ",", 24 } },
	// State 24: Reading second value of range
	{ { TokenType::Number, "", 25 }, { TokenType::Symbol, "-", 28 } },
	// State 25: Finished reading range
	{ { TokenType::Symbol, "}", 20 } },
	// State 26: Property value is negative
	{ { TokenType::Number, "", 20 } },
	// State 27: First number of range is negative
	{ { TokenType::Number, "", 23 } },
	// State 28: Second number of range is negative
	{ { TokenType::Number, "", 25 } }
};

bool IsStructType(const std::string& str)
{
	// TODO
	return false;
}

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

bool State6(BPScriptParser* Parser, struct Token* Tok)
{
	// Erase previous tokens, that way we only see the ones we haven't completely parsed.
	EmptyPastTokens(Parser);
	return true;
}

bool State7(BPScriptParser* Parser, struct Token* Tok)
{
	Parser->CurrentVariable = new BPVariable();
	Parser->CurrentVariable->DataType = Tok->val;

	if (IsStructType(Tok->val))
	{
		Parser->CurrentVariable->Type = BPVariableType::Struct;
		Parser->CurrentVariable->RefType = '\0';
	}
	else
	{
		Parser->CurrentVariable->Type = BPVariableType::Object;
	}

	return true;
}

bool State8(BPScriptParser* Parser, struct Token* Tok)
{
	Parser->CurrentVariable->RefType = Tok->val[0];
	return true;
}

bool State9(BPScriptParser* Parser, struct Token* Tok)
{
	Parser->CurrentClass->Arrays.push_back(Parser->CurrentVariable);
	return true;
}

bool State11(BPScriptParser* Parser, struct Token* Tok)
{
	Parser->CurrentClass->Sets.push_back(Parser->CurrentVariable);
	return true;
}

bool State12(BPScriptParser* Parser, struct Token* Tok)
{
	Parser->CurrentMap = new BPMap();
	Parser->CurrentMap->Key_DataType = Parser->CurrentVariable->DataType;
	Parser->CurrentMap->Key_RefType = Parser->CurrentVariable->RefType;
	Parser->CurrentMap->Key_Type = Parser->CurrentVariable->Type;
	delete Parser->CurrentVariable;
	Parser->CurrentVariable = nullptr;
	Parser->CurrentClass->Maps.push_back(Parser->CurrentMap);
	return true;
}

bool State13(BPScriptParser* Parser, struct Token* Tok)
{
	Parser->CurrentMap->Value_DataType = Tok->val;

	if (IsStructType(Tok->val))
	{
		Parser->CurrentMap->Value_Type = BPVariableType::Struct;
		Parser->CurrentMap->Value_RefType = '\0';
	}
	else
	{
		Parser->CurrentMap->Value_Type = BPVariableType::Object;
	}
	return true;
}

bool State14(BPScriptParser* Parser, struct Token* Tok)
{
	if (Parser->CurrentState == 12)
	{
		Parser->CurrentMap->Value_DataType = Tok->val;
		Parser->CurrentMap->Value_RefType = '\0';
		Parser->CurrentMap->Value_Type = BPVariableType::Primitive;
	}
	else if (Parser->CurrentState == 13)
	{
		Parser->CurrentMap->Value_RefType = Tok->val[0];
	}
	return true;
}

bool State15(BPScriptParser* Parser, struct Token* Tok)
{
	Parser->CurrentVariable->DataType = Tok->val;
	Parser->CurrentVariable->RefType = '\0';
	Parser->CurrentVariable->Type = BPVariableType::Primitive;
	return true;
}

bool State16(BPScriptParser* Parser, struct Token* Tok)
{
	if (Parser->CurrentVariable)
	{
		Parser->CurrentVariable->Name = Tok->val;
	}
	else
	{
		Parser->CurrentMap->Name = Tok->val;
	}

	if (Parser->CurrentState == 8)
	{
		Parser->CurrentClass->Variables.push_back(Parser->CurrentVariable);
	}
	return true;
}

bool (*STATE_FUNCTIONS[])(BPScriptParser*, struct Token*) = {
	State0, State1, nullptr, State3, nullptr, State5, State6,
	State7, State8, State9, nullptr, State11, State12, State13,
	State14, State15, State16
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
			|| t.type == TokenType::PrimitiveDT || t.type == TokenType::PropertyModifier
			|| t.value == tok->val))
		{
			// If the state function is valid, run it.
			if (STATE_FUNCTIONS[t.target_state] != nullptr)
			{
				// Run the state function. The success of this function
				// determines transition success.
				bool suc = STATE_FUNCTIONS[t.target_state](Parser, tok);

				// Change the current state.
				Parser->CurrentState = t.target_state;
				return suc;
			}
			else
			{
				// Otherwise, just accept the transition.
				// Change the current state.
				Parser->CurrentState = t.target_state;
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
			PastTokens.push_back(tok);

			if (!TryTransition(this, tok))
			{
				for (BPScriptClass* c : Classes)
				{
					UE_LOG(BPScript, Display, TEXT("Class: %s"), *FString(std::string(*c).c_str()));
				}
				UE_LOG(BPScript, Display, TEXT("Class: %s"), *FString(std::string(*CurrentClass).c_str()));
				EmptyPastTokens(this);
				fclose(token_file);
				fclose(read_file);
				return BAD_SCRIPT;
			}
		}
		//UE_LOG(BPScript, Display, TEXT("Token Type: %s\t\"%s\""), *enumToTokens[(int)tok->type], *FString(tok->val.c_str()));
	}

	fclose(token_file);
	fclose(read_file);
	return SUCCESS;
}
