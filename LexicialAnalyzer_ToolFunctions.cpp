#pragma once
#include "stdafx.h"
#include "LexicialAnalyzer.h"

void LexicialAnalyzerProgram::preprocessor()
{
	skipNBC();
	/*while (getChar() == "/")
	{
		nextChar();
		if (getChar() == "*")
		{
			while (true)
			{
				do
				{
					nextChar();
				} while (getChar() != "*");
				nextChar();
				if (getChar() == "/")
				{
					nextChar();
					break;
				}
			}
		}
		else if (getChar() == "/")
		{
			do
			{
				nextChar();
			} while (getChar() != "\n");
			nextChar();
		}
		else
		{
			lastChar();
			break;
		}

		skipNBC();
	}*/

}

void LexicialAnalyzerProgram::skipNBC()
{
	while (isNBC(getChar()))
	{
		nextChar();
	}
}

string LexicialAnalyzerProgram::getChar()
{
	return inputStream.substr(len, 1);
}

void LexicialAnalyzerProgram::nextChar()
{
	++len;
}

void LexicialAnalyzerProgram::lastChar()
{
	--len;
}

void LexicialAnalyzerProgram::catToken(string str, string &token)
{
	token += str;
}

string LexicialAnalyzerProgram::composeStrToken()
{
	string token = "";
	while (isLetter(getChar()) || isDigit(getChar()))
	{
		catToken(getChar(), token);
		nextChar();
	}

	return token;
}

string LexicialAnalyzerProgram::composeDigToken()
{
	string token = "";
	while (isDigit(getChar()))
	{
		catToken(getChar(), token);
		nextChar();
	}
	if (getChar() == ".")
	{
		nextChar();
		if (isDigit(getChar()))
		{
			catToken(".", token);
			while (isDigit(getChar()))
			{
				catToken(getChar(), token);
				nextChar();
			}
		}
		else
		{
			lastChar();
		}
	}
	return token;
}

