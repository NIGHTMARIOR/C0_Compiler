#pragma once
#include "WORD.h"

class SyntaxParser
{
public:
	SyntaxParser(vector<WORD> tokens);//TODO
	void Start();//TODO

private:
	void procedure();
	void constants_state_part();
	void constants_definition();
	void variables_state_part();
	void definition_front();
	void functions_state_part();
	void parameter();
	void parameter_table();
	void compound_statement();
	void statement();
	void main_function();
	void expression();
	void term();
	void factor();
	void condition_statement();
	void loop_statement();
	void statement_sequences();
	void function_call_statement();
	void assign_statement();
	void return_statement();
	void read_statement();
	void write_statement();
	void value_parameter_table();
	void condition();
	void string();

	WORD getToken();
	void nextToken();

	void KeyWord();
	void Identifier();
	void Constant();
	void Delimiter();
	void AddOperator();
	void MultiplyOperator();
	void Digit(); 
	void X(std::string x);

	vector<WORD> tokenStream;
	int len;
};