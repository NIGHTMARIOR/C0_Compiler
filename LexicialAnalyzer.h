#pragma once
#include "stdafx.h"
#include <regex>
#include <sstream>
#include "WORD.h"
#include "Error.h"
using namespace std;

class LexicialAnalyzerProgram
{
public:
	LexicialAnalyzerProgram(string);
	WORD GetToken();
private:
	string inputStream;
	int len = 0;
private:
	WORD decideWord();
	//判断函数
	bool isLetter(string);
	bool isDigit(string);
	bool isDelimiter(string);
	bool isOperator(string);
	bool isBinaryOperator(string);
	bool isNBC(string);
	bool isKeyword(string);
	bool isEOF(string);
	//获取函数
	WORD getStrToken();
	WORD getDigToken();
	WORD getDelToken();
	WORD getOperator();
	WORD getBinaryOperator(string);
	WORD getIllegalChar();
	//工具函数
	void skipNBC();
	string getChar();
	void nextChar();
	void lastChar();
	void catToken(string, string&);
	string composeStrToken();
	string composeDigToken();
	void preprocessor();
};