/* match.h - include this file for the match() function, encapsulating part *
 *           of std::regex_search's functionality for use from C programs   */

#pragma once
#ifndef MATCH_H
#define MATCH_H

#ifdef __cplusplus
extern "C" {
#endif

int match(const char* line, const char* pattern);
    /* returns 1 if line contains any matches of pattern, 0 otherwise */

#ifdef __cplusplus
}
#endif
#endif /* ! MATCH_H */