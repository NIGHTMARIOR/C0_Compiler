#pragma once
#include "stdafx.h"
#include "LexicialAnalyzer.h"

WORD LexicialAnalyzerProgram::getStrToken()
{
	string token = composeStrToken();

	try
	{
		if (!isNBC(getChar()) && !isDelimiter(getChar()) && !isOperator(getChar()) && !isEOF(getChar()))
		{
			throw IdetifierException();
		}
	}
	catch (const IdetifierException&)
	{
		return IllegalToken(token);
	}

	try
	{
		if (isKeyword(token))
			for (int i = 0; i < KeyWords.size(); i++)
				if (token == KeyWords[i].name)
				{
					if (getChar() == ";" || getChar() == ",")
						throw KeywordException();

					return KeyWords[i];
				}
	}
	catch (const KeywordException&)
	{
		return IllegalToken(token);
	}

	return Identifier(token);
}

WORD LexicialAnalyzerProgram::getDigToken()
{
	string token = composeDigToken();

	try
	{
		if (isLetter(getChar()))
		{
			throw ConstantException();
		}
		if (!isNBC(getChar()) && !isDelimiter(getChar()) && !isOperator(getChar()) && !isEOF(getChar()))
		{
			throw ConstantException();
		}
	}
	catch (const ConstantException&)
	{
		return IllegalToken(token);
	}

	return Constant(token);
}

WORD LexicialAnalyzerProgram::getDelToken()
{	
	string tmp = getChar();
	nextChar();

	return Delimiter(tmp);
}

WORD LexicialAnalyzerProgram::getOperator()
{
	string firstOperator = getChar();
	nextChar();
	if (isOperator(getChar()))
	{
		string binaryOperator = firstOperator;
		catToken(getChar(), binaryOperator);
		if (isBinaryOperator(binaryOperator))
		{
			nextChar();

			return getBinaryOperator(binaryOperator);
		}
	}

	return Operator(firstOperator);
}

WORD LexicialAnalyzerProgram::getBinaryOperator(string str)
{
	return BinaryOperator(str);
}

WORD LexicialAnalyzerProgram::getIllegalChar()
{
	string illegalChar = getChar();
	nextChar();
	return IllegalToken(illegalChar);
}

WORD LexicialAnalyzerProgram::decideWord()
{
	///*
	//if isLetter
	//	token = composeStrToken();
	//else if isDig
	//	token = composeDigToken();
	//else if isOpe
	//	token = composeOpe();
	//else
	//	token = getChar();

	//try
	//{
	//	if ()
	//		throw
	//}
	//catch
	//{
	//	return IllegalToken(token)
	//}

	//*/

	//if (isLetter(getChar()))
	//{
	//	//get the word
	//	string token = composeStrToken();
	//	//illegal word
	//	try
	//	{
	//		if (getChar() != " " && getChar() != "\t" && getChar() != "\n")
	//		{
	//			throw IdetifierException();
	//		}
	//	}
	//	catch (const IdetifierException&)
	//	{
	//		return IllegalToken(token);
	//	}
	//	//isKeyWord
	//	for (int i = 0; i < KeyWords.size(); i++)
	//		if (token == KeyWords[i].name)
	//			return KeyWords[i];
	//	//isIdentifier
	//	return Identifier(token);
	//}
	//if (isDigit(getChar()))
	//{
	//	string token = composeDigToken();

	//	try
	//	{
	//		if (getChar() != " " && getChar() != "\t" && getChar() != "\n")
	//		{
	//			throw ConstantException();
	//		}
	//	}
	//	catch (const ConstantException&)
	//	{
	//		return IllegalToken(token);
	//	}

	//	return Constant(token);
	//}
	//if (isDelimiter(getChar()))
	//{
	//	string token = getChar();
	//	nextChar();

	//	return Delimiter(token);
	//}
	//if (isOperator(getChar()))
	//{
	//	string firstOperator = getChar();
	//	nextChar();
	//	if (getChar() != " ")
	//	{
	//		string binaryOperator = firstOperator;
	//		catToken(getChar(), binaryOperator);
	//		try
	//		{
	//			if (isBinaryOperator(binaryOperator))
	//			{
	//				return getBinaryOperator(binaryOperator);
	//			}
	//		}
	//		catch (const BinaryOperatorException&)
	//		{
	//			return IllegalToken(binaryOperator);
	//		}
	//	}

	//	return Operator(firstOperator);
	//}
	//if (isEOF(getChar()))
	//{
	//	throw EOFException();
	//}
	//return IllegalToken(getChar());
	return WORD();
}