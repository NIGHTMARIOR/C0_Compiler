#include "stdafx.h"
#include "SyntaxParser.h"

SyntaxParser::SyntaxParser(vector<WORD> tokens)
{
	this->tokenStream = tokens;
	len = 0;
}

void SyntaxParser::Start()
{
	procedure();
}

void SyntaxParser::procedure()
{
	constants_state_part();
	variables_state_part();
	functions_state_part();
	main_function();
}

void SyntaxParser::constants_state_part()
{
	//检查第一个字符是否为const
	//if (!X("const"))
	//	throw exception();//TODO:选择正确的exception类型
	//nextToken();
	X("const");

	//TODO:怎么结束循环
	while (true)
	{
		constants_definition();
	}
}

void SyntaxParser::constants_definition()
{
	//if (!Identifier())
	//	throw exception();//TODO: exact kind
	//nextToken();
	Identifier();

	//if (!X("="))
	//	throw exception(); //TODO:exact kind;
	//nextToken();
	X("=");

	//if (!Constant())
	//	throw exception(); //TODO: exact kind;
	//nextToken();
	Constant();
}

void SyntaxParser::variables_state_part()
{
	definition_front();

	//TODO:how to break loop
	while (true)
	{
		//if (!X(","))
		//	throw exception(); //TODO:exact kind;
		//nextToken();
		X(",");

		Identifier();
	}
}

void SyntaxParser::definition_front()
{
	X("int");
	Identifier();
}

void SyntaxParser::functions_state_part()
{
	//TODO:logically wrong
	if (getToken() == "int")
		definition_front();
	else if (getToken() == "void")
		Identifier();
	else
		throw exception();//TODO

	parameter();
	compound_statement();
}

void SyntaxParser::parameter()
{
	X("(");
	parameter_table();
	X(")");
}

void SyntaxParser::parameter_table()
{
	if (getToken() == "int")
	{
		//TODO
		while (true)
		{
			X("int");
			Identifier();
		}
	}
	else
	{

	}
}

void SyntaxParser::compound_statement()
{
	X("{");
	//TODO
	while (true)
	{
		constants_state_part();
	}
	while (true);
	{
		variables_state_part();
	}
	statement_sequences();
	X("}");
}

void SyntaxParser::statement()
{
	if (getToken() == "if")
	{
		condition_statement();
	}
	else if (getToken() == "while")
	{
		loop_statement();
	}
	else if (getToken() == "{")
	{
		X("{");
		statement_sequences();
		X("}");
	}
	else if (true)//TODO:function call
	{
		function_call_statement();
	}
	else if (true)//TODO:assign statement
	{
		assign_statement();
	}
	else if (getToken() == "return")
	{
		return_statement();
	}
	else if (getToken() == "read")
	{
		read_statement();
	}
	else if (getToken() == "write")
	{
		write_statement();
	}
	else
	{

	}
}

void SyntaxParser::main_function()
{
	if (getToken() != "void" && getToken() != "int")
		throw exception();//TODO
	X("main");
	parameter();
	compound_statement();
}

void SyntaxParser::expression()
{
	if (getToken() == "+" || getToken() == "-")
	{
		nextToken();
	}
	term();
	//TODO
	while (true)
	{
		if (getToken() != "+" && getToken() != "-")
			throw exception(); //TODO
		term();
	}
}

void SyntaxParser::term()
{
	factor();
	//TODO
	while (true)
	{
		if (getToken() != "*" && getToken() != "/")
			throw exception();
		factor();
	}
}

void SyntaxParser::factor()
{
	//TODO
	if (true)
	{
		Identifier();
	}
	else if (true)
	{
		X("(");
		expression();
		X(")");
	}
	else if (true)
	{
		Digit();
	}
	else if (true)
	{
		function_call_statement();
	}
}

void SyntaxParser::condition_statement()
{
	X("if");
	X("(");
	condition();
	X(")");
	statement();
	//TODO
	while (true)
	{
		X("else");
		statement();
	}
}

void SyntaxParser::loop_statement()
{
	X("while");
	X("(");
	condition();
	X(")");
	statement();
}

void SyntaxParser::statement_sequences()
{
	statement();
	//TODO
	while (true)
	{
		statement();
	}
}

void SyntaxParser::function_call_statement()
{
	Identifier();
	X("(");
	value_parameter_table();
	X(")");
}

void SyntaxParser::assign_statement()
{
	Identifier();
	X("=");
	expression();
}

void SyntaxParser::return_statement()
{
	X("return");
	//TODO
	if (getToken() == "(")
	{
		expression();
		X(")");
	}
}

void SyntaxParser::read_statement()
{
	X("scanf");
	X("(");
	expression();
	X(")");
}

void SyntaxParser::write_statement()
{
	X("printf");
	X("(");
	string();
	X(",");
	//TODO
	if (true)
	{
		expression();
	}
	X(")");
}

void SyntaxParser::value_parameter_table()
{
	expression();
	//TODO
	while (true)
	{
		X(",");
		expression();
	}
}

void SyntaxParser::condition()
{
	//TODO
	if (true)
	{
		expression();
		MultiplyOperator();
		expression();
	}
	else if (true)
	{
		expression();
	}
	else
		throw exception();
}

void SyntaxParser::string()
{
}

WORD SyntaxParser::getToken()
{
	return tokenStream[len];
}

void SyntaxParser::nextToken()
{
	++len;
}

void SyntaxParser::KeyWord()
{
	if (getToken().kind != "KEYWORD")
		throw exception(); //TODO
	nextToken();
}

void SyntaxParser::Identifier()
{
	if (getToken().kind != "IDENTIFIER")
		throw exception(); //TODO
	nextToken();
}

void SyntaxParser::Constant()
{
	if (getToken().kind != "CONSTANT")
		throw exception(); //TODO
	nextToken();
}

void SyntaxParser::Delimiter()
{
	if (getToken().kind != "DELIMITER")
		throw exception(); //TODO
	nextToken();
}

void SyntaxParser::AddOperator()
{
	if (getToken().kind != "ADDOPERATOR")
		throw exception(); //TODO
	nextToken();
}

void SyntaxParser::MultiplyOperator()
{
	if (getToken().kind != "MULTIPLYOPERATOR")
		throw exception(); //TODO
	nextToken();
}

void SyntaxParser::Digit()
{
	if (getToken().kind != "DIGIT")
		throw exception(); //TODO
	nextToken();
}

void SyntaxParser::X(std::string x)
{
	if (getToken().name != x)
		throw exception(); //TODO
	nextToken();
}
