/* noreturn.h - semi-portable noreturn macro header */

#pragma once
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