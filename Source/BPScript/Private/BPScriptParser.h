
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

	operator std::string() const
	{
		std::string val = DataType;
		if (Type == BPVariableType::Object)
		{
			val += RefType;
		}
		val += ' ';
		val += Name;
		return val;
	}
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
	operator std::string() const
	{
		std::string val = Key_DataType;
		if (Key_Type == BPVariableType::Object)
		{
			val += Key_RefType;
		}
		val += ':';
		val += Value_DataType;
		if (Value_Type == BPVariableType::Object)
		{
			val += Value_RefType;
		}
		val += ' ';
		val += Name;
		return val;
	}
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
		if (Variables.size() > 0)
		{
			val += "\n\n === Variables === ";
			for (BPVariable* Vars : Variables)
			{
				val += "\n" + std::string(*Vars);
			}
		}
		if (Arrays.size() > 0)
		{
			val += "\n\n === Arrays === ";
			for (BPVariable* Vars : Arrays)
			{
				val += "\n" + std::string(*Vars);
			}
		}
		if (Sets.size() > 0)
		{
			val += "\n\n === Sets === ";
			for (BPVariable* Vars : Sets)
			{
				val += "\n" + std::string(*Vars);
			}
		}
		if (Maps.size() > 0)
		{
			val += "\n\n === Maps === ";
			for (BPMap* Vars : Maps)
			{
				val += "\n" + std::string(*Vars);
			}
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

	BPVariable* CurrentVariable;
	BPMap* CurrentMap;
	int CurrentState = 0;

	int ReadScript(std::string filename);
};
