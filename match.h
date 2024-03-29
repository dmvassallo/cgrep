/*
  match.h - Include this file for the match() function, encapsulating part of
            std::regex_search's functionality for use from C programs.

  Copyright (c) 2015, 2023 David Vassallo and Eliah Kagan

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

/* match.h - include this file for the match() function, encapsulating part *
 *           of std::regex_search's functionality for use from C programs   */

#ifndef MATCH_H
#define MATCH_H

#ifdef __cplusplus
extern "C" {
#endif

/* Returns 1 if line contains any matches of pattern, 0 otherwise. */
int match(const char* line, const char* pattern);

#ifdef __cplusplus
}
#endif
#endif /* ! MATCH_H */
