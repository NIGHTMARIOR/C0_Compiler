#pragma once
#include "stdafx.h"
#include "LexicialAnalyzer.h"


bool LexicialAnalyzerProgram::isLetter(string str)
{
	string pattern{ "[A-Za-z]" };
	regex re(pattern);
	return regex_match(str, re);
}

bool LexicialAnalyzerProgram::isDigit(string str)
{
	regex pattern("[0-9]");
	return regex_match(str, pattern);
}

bool LexicialAnalyzerProgram::isDelimiter(string str)
{
	for (int i = 0; i < Delimiters.size(); i++)
		if (str == Delimiters[i].name)
			return true;

	return false;
}

bool LexicialAnalyzerProgram::isOperator(string str)
{
	for (int i = 0; i < Operators.size(); i++)
		if (str == Operators[i].name)
			return true;
	if (str == ":")
	{
		nextChar();
		try
		{
			if (getChar() == "=")
			{
				lastChar();
				return true;
			}
		}
		catch (const std::exception&)
		{
		}
		lastChar();
	}
	return false;
}

bool LexicialAnalyzerProgram::isBinaryOperator(string str)
{
	for (int i = 0; i < BinaryOperators.size(); i++)
		if (str == BinaryOperators[i].name)
			return true;

	return false;
}

bool LexicialAnalyzerProgram::isNBC(string chr)
{
	return chr == " " || chr == "\t" || chr == "\n";
}

bool LexicialAnalyzerProgram::isKeyword(string token)
{
	for (int i = 0; i < KeyWords.size(); i++)
		if (token == KeyWords[i].name)
			return true;
	return false;
}

bool LexicialAnalyzerProgram::isEOF(string token)
{
	return token == "" ? true : false;
}
