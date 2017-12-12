#pragma once
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#include <exception>
using namespace std;

class BinaryOperatorException : public exception
{

};

class IdetifierException : public exception
{

};

class ConstantException : public exception
{

};

class EOFException : public exception
{

};

class NoteException : public exception
{

};

class EndException : public exception
{

};

class KeywordException : public exception
{

};