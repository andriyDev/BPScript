
#pragma once

#include "BPScriptTokenizer.h"

#include <vector>

#define SUCCESS 0
#define BAD_FILE 1
#define BAD_SCRIPT 2

enum BPVariableType
{
	Primitive, Struct, Object
};

class BPVariable
{
public:
	std::string Name;

	BPVariableType Type;
	std::string DataType;
	char RefType;
};

class BPMap
{
public:
	std::string Name;

	BPVariableType Key_Type;
	std::string Key_DataType;
	char Key_RefType;

	BPVariableType Value_Type;
	std::string Value_DataType;
	char Value_RefType;
};

class BPScriptClass
{
public:
	std::string ClassName;
	std::string Parent;
	std::vector<std::string> Interfaces;
	std::vector<BPVariable*> Variables;
	std::vector<BPVariable*> Arrays;
	std::vector<BPVariable*> Sets;
	std::vector<BPMap*> Maps;

	operator std::string() const
	{
		std::string val = ClassName + " : " + Parent + " | ";
		bool initial = true;
		for (std::string Interface : Interfaces)
		{
			if (!initial)
			{
				val += ", ";
			}
			else
			{
				initial = false;
			}
			val += Interface;
		}
		return val;
	}
};

class BPScriptParser
{
public:
	std::vector<BPScriptClass*> Classes;
	std::vector<struct Token*> PastTokens;
	BPScriptClass* CurrentClass;
	int CurrentState = 0;

	int ReadScript(std::string filename);
};
