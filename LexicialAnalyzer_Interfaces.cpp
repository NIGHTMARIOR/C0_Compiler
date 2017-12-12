#pragma once
#include "stdafx.h"
#include "LexicialAnalyzer.h"


LexicialAnalyzerProgram::LexicialAnalyzerProgram(string inputStream)
{
	this->inputStream = inputStream;
}

//TODO:这个地方能用多态实现吗？太多条件和类似的分支很难受。
WORD LexicialAnalyzerProgram::GetToken()
{
	preprocessor();

	if (isLetter(getChar()))
	{
		return getStrToken();
	}
	if (isDigit(getChar()))
	{
		return getDigToken();
	}
	if (isDelimiter(getChar()))
	{
		return getDelToken();
	}
	if (isOperator(getChar()))
	{
		return getOperator();
	}
	if (isEOF(getChar()))
	{
		throw EOFException();
	}

	return getIllegalChar();
}


