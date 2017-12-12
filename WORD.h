#pragma once

#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#include <string>
#include <vector>
using namespace std;

enum KIND
{
	KEYWORD,
	IDENTIFIER,
	CONSTANT,
	DELIMITER,
	OPERATOR,
	BINARYOPERATOR,
	ERROR
};

class WORD
{
public:
	WORD();
	WORD(string _name);

	void operator=(WORD A);
	bool operator==(WORD A);
	bool operator!=(WORD A);
	
	string name;
	string kind;

	WORD GetName();
};

class KeyWord : public WORD
{
public:
	KeyWord(string);
};

class Identifier : public WORD
{
public:
	Identifier(string);
};

class Constant : public WORD
{
public:
	Constant(string);
};

class Delimiter : public WORD
{
public:
	Delimiter(string);
};

class Operator : public WORD
{
public:
	Operator(string);
};

class BinaryOperator : public WORD
{
public:
	BinaryOperator(string);
};

class IllegalToken : public WORD
{
public:
	IllegalToken(string);
};

extern const vector<KeyWord> KeyWords;
extern const vector<Delimiter> Delimiters;
extern const vector<Operator> Operators;
extern const vector<BinaryOperator> BinaryOperators;
