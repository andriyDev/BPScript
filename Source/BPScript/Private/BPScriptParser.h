
#pragma once

#include "BPScriptTokenizer.h"

#include <vector>
#include <string>

#define SUCCESS 0
#define BAD_FILE 1
#define BAD_SCRIPT 2

enum BPVariableType
{
	Primitive, Struct, Object
};

class BPProperty
{
public:
	std::string Name;

	BPProperty(const std::string& Name)
	{
		this->Name = Name;
	}

	virtual ~BPProperty() {}

	virtual operator std::string() const
	{
		return Name;
	}
};

class BPBoolProperty : public BPProperty
{
public:
	bool Value;

	BPBoolProperty(const std::string& Name, bool Value)
		: BPProperty(Name)
	{
		this->Value = Value;
	}

	BPBoolProperty(const std::string& Name)
		: BPProperty(Name)
	{
		this->Value = true;
	}

	virtual operator std::string() const override
	{
		return Name + ": " + (Value ? "true" : "false");
	}
};

class BPNumberProperty : public BPProperty
{
public:
	float Value;

	BPNumberProperty(const std::string& Name, float Value)
		: BPProperty(Name)
	{
		this->Value = Value;
	}

	BPNumberProperty(const std::string& Name)
		: BPProperty(Name)
	{
		this->Value = 0;
	}

	virtual operator std::string() const override
	{
		return Name + ": " + std::to_string(Value);
	}
};

class BPRangeProperty : public BPProperty
{
public:
	float ValueStart;
	float ValueEnd;

	BPRangeProperty(const std::string& Name, float ValueStart, float ValueEnd)
		: BPProperty(Name)
	{
		this->ValueStart = ValueStart;
		this->ValueEnd = ValueEnd;
	}

	BPRangeProperty(const std::string& Name)
		: BPProperty(Name)
	{
		this->ValueStart = 0;
		this->ValueEnd = 1;
	}

	virtual operator std::string() const override
	{
		return Name + ": {" + std::to_string(ValueStart) + ", " + std::to_string(ValueEnd) + "}";
	}
};

class BPIdentifierProperty : public BPProperty
{
public:
	std::string Value;

	BPIdentifierProperty(const std::string& Name, const std::string& Value)
		: BPProperty(Name)
	{
		this->Value = Value;
	}

	BPIdentifierProperty(const std::string& Name)
		: BPProperty(Name)
	{
		this->Value = "";
	}

	virtual operator std::string() const override
	{
		return Name + ": " + Value;
	}
};

class BPStringProperty : public BPProperty
{
public:
	std::string Value;

	BPStringProperty(const std::string& Name, const std::string& Value)
		: BPProperty(Name)
	{
		this->Value = Value.substr(1, Value.length() - 2);
	}

	BPStringProperty(const std::string& Name)
		: BPProperty(Name)
	{
		this->Value = "";
	}

	virtual operator std::string() const override
	{
		return Name + ": \"" + Value + '"';
	}
};

class BPField
{
public:
	std::string Name;

	std::vector<BPProperty*> Properties;

	~BPField()
	{
		for (BPProperty* Prop : Properties)
		{
			delete Prop;
		}
	}
};

class BPVariable : public BPField
{
public:

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

		if (Properties.size() > 0)
		{
			val += " <";
			bool initial = true;
			for (BPProperty* Prop : Properties)
			{
				if (initial)
				{
					initial = false;
				}
				else
				{
					val += ", ";
				}
				val += std::string(*Prop);
			}
			val += ">";
		}

		return val;
	}
};

class BPMap : public BPField
{
public:
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

		if (Properties.size() > 0)
		{
			val += " <";
			bool initial = true;
			for (BPProperty* Prop : Properties)
			{
				if (initial)
				{
					initial = false;
				}
				else
				{
					val += ", ";
				}
				val += std::string(*Prop);
			}
			val += ">";
		}

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

	~BPScriptClass()
	{
		for (BPVariable* var : Variables)
		{
			delete var;
		}

		for (BPVariable* arr : Arrays)
		{
			delete arr;
		}

		for (BPVariable* set : Sets)
		{
			delete set;
		}

		for (BPMap* map : Maps)
		{
			delete map;
		}
	}

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
	std::string CurrentPropertyName;
	float CurrentStartRangeValue;
	int CurrentState = 0;

	int ReadScript(std::string filename);
};
