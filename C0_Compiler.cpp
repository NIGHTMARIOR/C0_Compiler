#include "stdafx.h"
#include "C0_Compiler.h"


C0_Compiler::C0_Compiler(string sourceCode) : LAP(sourceCode)
{

}


C0_Compiler::~C0_Compiler()
{
}

void C0_Compiler::Start()
{
	while (true)
	{
		try
		{
			tokenStream.push_back(LAP.GetToken());
		}
		catch (EOFException)
		{
			break;
		}
	}
}
