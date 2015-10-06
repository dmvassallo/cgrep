/* cgrep.c - simple console grep - less powerful egrep-like program in C89  *
 *           This utility shows how to use C and C++ together in a program. */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "match.h"
#include "readln.h"
#include "noreturn.h"

static const char *g_progname = NULL; /* set in main() */

noreturn static void die(const char *msg)
{
    fprintf(stderr, "%s: error: %s\n", g_progname, msg);
    exit(EXIT_FAILURE);
}

static void xputs(const char *a)
{
    if (puts(a) == EOF) die("failure writing to standard output");
}

static void grep(const char *line, const char *pattern)
{
    if (match(line, pattern)) xputs(line);
    else if (errno == EINVAL) die("invalid regular expression");
}

int main(int argc, char *argv[])
{
    char* line;
    g_progname = argv[0];

    switch (argc) {
        case 2:         break;
        case 1:         die("too few arguments (need regexp pattern)");
        default:        die("too many arguments (only one pattern accepted)");
    }

    while ((line = readln()) != NULL) grep(line, argv[1]);

    switch (errno) { /* find out why readln() couldn't get another line */
        case 0:         break;
        case EIO:       die("couldn't read from standard input");
        case ENOMEM:    die("out of memory (can't store input)");
    }

    freeln(line);
    /* "TODO": More code here, that justifies bothering to call freeln()  *
     *         before program termination (which frees all heap memory).  */
    return EXIT_SUCCESS;
}