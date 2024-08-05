#include "InputException.h"

const char* InputException::what() const noexcept
{
	return "the Input is the worng type!";
}
