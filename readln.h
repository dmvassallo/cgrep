/*
  readln.h - Include this file for the readln() function, which wraps the C++
             std::getline, for use in C89 (and later).

  Copyright (c) 2015 David Vassallo and Eliah Kagan

  Permission to use, copy, modify, and/or distribute this software for any
  purpose with or without fee is hereby granted.

  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
  REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
  AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
  INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
  LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
  OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
  PERFORMANCE OF THIS SOFTWARE.
*/

#ifndef READLN_H
#define READLN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Read a line from standard input and return a pointer to it. */
char* readln();

/* Free the memory returned by readln(). */
void freeln(char *);

#ifdef __cplusplus
}
#endif
#endif /* ! RETURN_H */
