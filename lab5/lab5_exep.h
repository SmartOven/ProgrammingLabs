#pragma once
#include <exception>


class Exception : public std::exception {};

class ExistExeption : public Exception
{
	const char* what() const throw() override
	{
		return "Matrix is smaller then index!\n";
	}
};

class EmptyStackException : public Exception
{
	const char* what() const throw() override {
		return "Stack is empty!\n";
	}
};