// readln.cpp - readln() function implementation (wraps std::getline)
//
// Copyright (c) 2015 David Vassallo and Eliah Kagan
//
// Permission to use, copy, modify, and/or distribute this software for any
// purpose with or without fee is hereby granted.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
// WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
// SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
// OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
// CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

#include "readln.h"

#include <iostream>
#include <cerrno>
#include <string>

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
