
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

	// Variable Parsing
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
	{  }
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

bool State6(BPScriptParser* Parser, struct Token* Tok)
{
	// Erase previous tokens, that way we only see the ones we haven't completely parsed.
	EmptyPastTokens(Parser);
	return true;
}

bool State7(BPScriptParser* Parser, struct Token* Tok)
{
	// TODO: CHECK IF IDENTIFIER IS A UOBJECT OR A STRUCT TYPE THING
	return true;
}

bool State14(BPScriptParser* Parser, struct Token* Tok)
{
	// TODO: CHECK IF IDENTIFIER IS A UOBJECT OR A STRUCT TYPE THING
	return true;
}

bool State16(BPScriptParser* Parser, struct Token* Tok)
{
	if (Parser->PastTokens[1]->val == std::string(":") || Parser->PastTokens[2]->val == std::string(":"))
	{
		// Variable is a map.
		BPMap* NewVar = new BPMap();

		// This is the position of the value data type
		int second_var;

		// Assign the data type of the key.
		NewVar->Key_DataType = Parser->PastTokens[0]->val;
		if (Parser->PastTokens[0]->type == TokenType::PrimitiveDT)
		{
			// The key is primitive.
			NewVar->Key_Type = BPVariableType::Primitive;
			NewVar->Key_RefType = '\0';
			second_var = 2;
		}
		else if (Parser->PastTokens[1]->val[0] == '*' || Parser->PastTokens[1]->val[0] == '&'
			|| Parser->PastTokens[1]->val[0] == '$' || Parser->PastTokens[1]->val[0] == '#')
		{
			// The key is an object reference
			NewVar->Key_Type = BPVariableType::Object;
			NewVar->Key_RefType = Parser->PastTokens[1]->val[0];
			second_var = 3;
		}
		else
		{
			// The key is a struct
			NewVar->Key_Type = BPVariableType::Struct;
			NewVar->Key_RefType = '\0';
			second_var = 2;
		}

		// Assign the value data type
		NewVar->Value_DataType = Parser->PastTokens[second_var]->val;
		if (Parser->PastTokens[second_var]->type == TokenType::PrimitiveDT)
		{
			// The value is primitive
			NewVar->Value_Type = BPVariableType::Primitive;
			NewVar->Value_RefType = '\0';
		}
		else if (Parser->PastTokens[second_var + 1]->val[0] == '*' || Parser->PastTokens[second_var + 1]->val[0] == '&'
			|| Parser->PastTokens[second_var + 1]->val[0] == '$' || Parser->PastTokens[second_var + 1]->val[0] == '#')
		{
			// The value is an object
			NewVar->Value_Type = BPVariableType::Object;
			NewVar->Value_RefType = Parser->PastTokens[second_var + 1]->val[0];
		}
		else
		{
			// The value is a struct
			NewVar->Value_Type = BPVariableType::Struct;
			NewVar->Value_RefType = '\0';
		}
		Parser->CurrentClass->Maps.push_back(NewVar);
	}
	else
	{
		// Make a new variable
		BPVariable* NewVar = new BPVariable();

		// Add it to the correct list.
		if (Parser->PastTokens[Parser->PastTokens.size() - 2]->val == std::string("}"))
		{
			// Variable is a set.
			Parser->CurrentClass->Sets.push_back(NewVar);
		}
		else if (Parser->PastTokens[Parser->PastTokens.size() - 2]->val == std::string("]"))
		{
			// Variable is an array.
			Parser->CurrentClass->Arrays.push_back(NewVar);
		}
		else
		{
			// Variable is singular.
			Parser->CurrentClass->Variables.push_back(NewVar);
		}

		// Set the variable name and data type.
		NewVar->Name = Tok->val;
		NewVar->DataType = Parser->PastTokens[0]->val;
		// Assign the type of the data type.
		if (Parser->PastTokens[0]->type == TokenType::PrimitiveDT)
		{
			// The variable data type is a primitive
			NewVar->Type = BPVariableType::Primitive;
			NewVar->RefType = '\0';
		}
		else if (Parser->PastTokens[1]->val[0] == '*' || Parser->PastTokens[1]->val[0] == '&'
			|| Parser->PastTokens[1]->val[0] == '$' || Parser->PastTokens[1]->val[0] == '#')
		{
			// The variable data type is an object.
			NewVar->Type = BPVariableType::Object;
			NewVar->RefType = Parser->PastTokens[1]->val[0];
		}
		else
		{
			// The variable data type is a struct.
			NewVar->Type = BPVariableType::Struct;
			NewVar->RefType = '\0';
		}
	}

	return true;
}

bool (*STATE_FUNCTIONS[])(BPScriptParser*, struct Token*) = {
	State0, State1, nullptr, State3, nullptr, State5, State6,
	State7, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
	State14, nullptr, State16
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
			|| t.type == TokenType::PrimitiveDT || t.value == tok->val))
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
