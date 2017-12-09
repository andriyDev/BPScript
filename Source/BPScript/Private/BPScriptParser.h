
#pragma once

#include "BPScriptTokenizer.h"

#include <vector>

#define SUCCESS 0
#define BAD_FILE 1
#define BAD_SCRIPT 2

class BPScriptClass
{
public:
	std::string ClassName;
	std::string Parent;
	std::vector<std::string> Interfaces;

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
	BPScriptClass* CurrentClass;
	int CurrentState = 0;

	int ReadScript(std::string filename);
};
