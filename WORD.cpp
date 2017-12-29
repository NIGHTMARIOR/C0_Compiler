#pragma once
#include "stdafx.h"
#include "WORD.h"

WORD::WORD()
{
	WORD("");
}

WORD::WORD(string _name)
{
	name = _name;
	kind = "";
}

void WORD::operator=(WORD A)
{
	name = A.name;
}

bool WORD::operator==(WORD A)
{
	if (name != A.name)
		return false;

	return true;
}

bool WORD::operator==(string A)
{
	return false;
}

bool WORD::operator!=(string A)
{
	return false;
}

bool WORD::operator!=(WORD A)
{
	return !operator==(A);
}

WORD WORD::GetName()
{
	return WORD();
}

const vector<KeyWord> KeyWords =
{
	KeyWord("const"),
	KeyWord("procedure"),
	KeyWord("if"),
	KeyWord("else"),
	KeyWord("while"),
	KeyWord("read"),
	KeyWord("write"),
	KeyWord("int"),
	KeyWord("void"),
	KeyWord("scanf"),
	KeyWord("printf"),
	KeyWord("return"),
	KeyWord("main"),
};
const vector<Delimiter> Delimiters =
{
	Delimiter("("),
	Delimiter(")"),
	Delimiter(";"),
	Delimiter("."),
};
const vector<Operator> Operators =
{
	Operator("<"),
	Operator(">"),
	Operator("="),
	Operator("/"),
	Operator("+"),
	Operator("-"),
	Operator("*"),
	Operator(","),
	Operator(";"),
};
const vector<BinaryOperator> BinaryOperators =
{
	BinaryOperator("<="),
	BinaryOperator(">="),
	BinaryOperator("<>"),
	BinaryOperator(":=")
};

IllegalToken::IllegalToken(string name) : WORD(name)
{
	kind = "ERROR";
}

KeyWord::KeyWord(string name) : WORD(name)
{
	kind = "KEYWORD";
}

Identifier::Identifier(string name) : WORD(name)
{
	kind = "IDENTIFIER";
}

Delimiter::Delimiter(string name) : WORD(name)
{
	kind = "DELIMITER";
}

Operator::Operator(string name) : WORD(name)
{
	kind = "OPERATOR";
}

BinaryOperator::BinaryOperator(string name) : WORD(name)
{
	kind = "BINARYOPERATOR";
}

Constant::Constant(string name) : WORD(name)
{
	kind = "CONSTANT";
}
