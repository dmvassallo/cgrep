<!-- SPDX-License-Identifier: 0BSD -->

# cgrep - simple console grep

This utility shows how to use C and C++ together in a program. It is a simple
console-based grep utility, like [`egrep`](https://linux.die.net/man/1/egrep)
but less powerful. The specific scenario this demonstrates is calling C++ code
from C code.

It is equally important to be able to call C code from C++ code, but that isn't
covered here, because it's simpler and less in need of demonstration. One need
not (hardly ever) write wrapper functions to allow C code to be consumed in
C++, because C++ is mostly compatible with C and supports most of its type
system.

The C code here is compatible with
[C89](https://en.wikipedia.org/wiki/ANSI_C#C89).

## License

[0BSD](https://spdx.org/licenses/0BSD). See [**`LICENSE`**](LICENSE).

## Building

You can build with CMake, or manually, on both Unix-like systems and Windows.
If your IDE supports CMake (this includes VS Code with the recommended C++
extensions), then you don't need to use the command-line. If you build
manually, the specific commands vary depending on your compiler.

**See [`building.md`](building.md) for build instructions.**

## Parts of this program

In C:

- [`cgrep.c`](cgrep.c) contains the program entry point (`main` function), and
  basic logic to parse command-line arguments to report results and errors.
- For other functionality, the C code calls into C++.

In C++:

- [`readln.cpp`](readln.cpp) reads line-based input, wrapping
  [`std::getline`](https://en.cppreference.com/w/cpp/string/basic_string/getline)
  for consumption in C.
- [`match.cpp`](match.cpp) does the actual regular expression matching,
  wrapping
  [`std::regex_search`](https://en.cppreference.com/w/cpp/regex/regex_search)
  for consumption in C.

The header files—[`match.h`](match.h), [`noreturn.h`](noreturn.h), and
[`readln.h`](readln.h)—are written to be usable, without modification, in
either C or C++ (and are used in that manner).
