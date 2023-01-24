/*
  noreturn.h - semi-portable noreturn macro header

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

#ifndef NORETURN_H
#define NORETURN_H

#if __STDC_VERSION__ >= 201112L /* C11 */
#include <stdnoreturn.h>
#elif defined(__cplusplus)
#define noreturn [[noreturn]]
#elif defined(_MSC_VER) /* Microsoft Visual C++ */
#define noreturn __declspec(noreturn)
#elif defined(__GNUC__) || defined(__clang__)
#define noreturn __attribute__ ((noreturn))
#else
#define noreturn
#endif

#endif /* ! NORETURN_H */
