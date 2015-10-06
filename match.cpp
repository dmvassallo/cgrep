// match.cpp - match() function implementation (uses std::regex_search)

#include "match.h"

#include <cerrno>
#include <regex>

extern "C" int match(const char* line, const char* pattern)
{
    try {
        std::cmatch m;
        return std::regex_search(line, m, std::regex{pattern}) ? 1 : 0;
    }
    catch (const std::regex_error&) {
        errno = EINVAL;
        return 0;
    }
}