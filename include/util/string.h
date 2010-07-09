#ifndef __UTIL_STRING_H__
#define __UTIL_STRING_H__

#include <stdarg.h>

/**
 * Returns true if s1 matches s2.
 */
int streq(const char *s1, const char *s2);

/**
 * Returns true if the given string starts with the specified prefix.
 */
int starts_with(const char *s, const char *prefix);

/**
 * Returns true if the given string ends with the specified suffix.
 */
int ends_with(const char *s, const char *suffix);

/**
 * Returns true if the given NULL-terminated array contains a string
 * that matches the given string.
 */
int contains_string(const char **array, const char *s);

/**
 * Returns true if the given string matches one of the following strings.
 * The final argument should be NULL.
 */
int string_in(const char *s, ...);

/**
 * Replaces the first whitespace character in the given string with a
 * null-terminator, and returns a pointer to the first following
 * non-whitespace character. Returns NULL if there is no such character.
 */
char *split(char *s);

/**
 * Analog of strcat(), except calls realloc() to ensure the allocated space is
 * large enough.
 */
char *astrcat(char **dest, const char *src);

/**
 * Equivalent to astrcat(), except src is free()'d afterwards.
 */
char *astrcatf(char **dest, char *src);

/**
 * Advance the given pointer to the first non-whitespace character.
 */
void ltrim(char **s);

/**
 * Replace trailing whitespace characters with a null-terminator.
 */
void rtrim(char **s);

/**
 * Trim leading and trailing whitespace from the given string.
 */
void trim(char **s);

/**
 * Replace the first occurence of c in s with z, and return a pointer to the
 * character.
 */
char *strchrr(char *s, char c, char z);

#endif
