#pragma once
#include "LexicialAnalyzer.h"
#include "WORD.h"
#include <string>
#include <vector>

typedef vector<WORD> TokenStream;

class C0_Compiler
{
public:
	C0_Compiler(string sourceCodef);
	~C0_Compiler();
	void Start();
private:
	LexicialAnalyzerProgram LAP;
	TokenStream tokenStream;
};

