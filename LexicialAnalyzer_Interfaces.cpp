#pragma once
#include "stdafx.h"
#include "LexicialAnalyzer.h"


LexicialAnalyzerProgram::LexicialAnalyzerProgram(string inputStream)
{
	this->inputStream = inputStream;
}

//TODO:����ط����ö�̬ʵ����̫�����������Ƶķ�֧�����ܡ�
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


