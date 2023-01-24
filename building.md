<!-- SPDX-License-Identifier: 0BSD -->

# Building

You can build with CMake, or manually, on both Unix-like systems and Windows.
If your IDE supports CMake (this includes VS Code with the recommended C++
extensions), then you don't need to use the command-line. If you build
manually, the specific commands vary depending on your compiler.

Unless you are using the [dev
container](https://docs.github.com/en/codespaces/setting-up-your-project-for-codespaces/adding-a-dev-container-configuration/introduction-to-dev-containers),
you must clone the repository and `cd` into its top-level directory before
building. One way to do that is to run:

```sh
git clone https://github.com/dmvassallo/cgrep.git
```

## With CMake

You'll need `cmake` and (except in situations detailed below) `ninja`. On most
systems, the package for `cmake` is called `cmake` and the package for `ninja`
is called either `ninja` or `ninja-build`. On Windows, one way to get them is
the [`scoop`](https://scoop.sh/) package manager (the `scoop` package for
`ninja` is `ninja`).

VS Code and some other editors/IDEs support CMake or have plugins to do so,
which may simplify building or selecting different compilers and build
variants.

To do a debug build with `cmake` from the command line using your default
compiler:

```sh
cd cgrep
mkdir build
cd build
cmake .. -G Ninja
cmake --build .
```

If you do that on Windows, you should make sure you are in an environment where
you have access to your toolchain, particularly if it is MSVC++ (the compiler
that is part of Microsoft Visual Studio). On Windows, MSVC++ is available in
Visual Studio PowerShell, but not (without added effort) in regular PowerShell
or Command Prompt windows.

On Unix-like systems, you can optionally omit `-G Ninja` to have `cmake` use
`make` instead of `ninja` for the build (though the build may be a bit slower).

## Manually

You can build without any build system. For example, if you are using GCC on a
Unix-like system, you can compile and link using the `gcc` and `g++` commands.
For a debug build:

```sh
gcc -ansi -pedantic-errors -Wall -Wextra -g -c cgrep.c
g++ -std=c++14 -pedantic-errors -Wall -Wextra -g -c match.cpp readln.cpp
g++ -o cgrep cgrep.o match.o readln.o
```

You can make a release build by passing `-O3` to optimize for speeed, or `-Os`
to optimize for size, instead of `-g` (which builds with debug symbols).

You can build manually with MSVC++ by using `cl.exe` instead of `gcc`, but the
available options and their meanings are different. Check your documentation
for details.
