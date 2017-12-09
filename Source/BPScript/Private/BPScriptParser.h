
#pragma once

#include "BPScriptTokenizer.h"

#include <vector>

class BPScriptClass
{
public:
	std::string Parent;
	std::vector<std::string> Interfaces;
};

class BPScriptParser
{
public:
	std::vector<BPScriptClass*> Classes;
	int CurrentState = 0;

	int ReadScript(std::string filename);
};
