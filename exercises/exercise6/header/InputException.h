#pragma once
#include <exception>

class InputException : public std::exception
{
public:
	virtual const char* what() const noexcept override;
};