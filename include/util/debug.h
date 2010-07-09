#ifndef __UTIL_DEBUG_H__
#define __UTIL_DEBUG_H__

#include <stdio.h>

/**
 * Macros for debugging output - compiled away in production build.
 */
#ifdef DEBUG
#   define DEBUG_PREFIX() \
            fprintf(stderr, "DEBUG:%s:%d: ", __FILE__, __LINE__)
#   define DEBUG_PRINTF(...) \
            (DEBUG_PREFIX(), fprintf(stderr, __VA_ARGS__))
#   define DEBUG_PERROR(s) \
            (DEBUG_PREFIX(), perror(s))
#else
#   define DEBUG_PRINTF(...) ((void) 0)
#   define DEBUG_PERROR(s) ((void) 0)
#endif

#endif
