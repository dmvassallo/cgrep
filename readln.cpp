#include <iostream>
#include <cerrno>
#include <string>
#include "readln.h"

using namespace std;  

extern "C" char* readln()
{
	string output;
	getline(std::cin, output);
	
	if(cin.bad())
	{
		errno = EIO;
		return nullptr; 
	}

	if (char* cstring = new(std::nothrow) char[output.size() + 1])
	{
		*std::copy(output.cbegin(), output.cend(), cstring) = '\0';
		return cstring;
	}
	else
	{
		errno = ENOMEM; 
		return nullptr;
	}
} 

extern "C" void freeln(char *inpline)
{
	delete[] inpline; 
}

