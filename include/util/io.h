#ifndef __UTIL_IO_H__
#define __UTIL_IO_H__

#include <stdarg.h>
#include <stdio.h>

/**
 * Read a line from the given file pointer, stripping the traling newline.
 * NULL is returned if an error or EOF is encountered.
 */
char *read_line(FILE *fp);

/**
 * Display a prompt and return the user input. ps1 and ps2 are the strings
 * used as the primary and secondary prompts. After each line is read from
 * the user, the given callback function is called with a pointer to the
 * accumulated input. If the callback returns true, another line is read.
 */
char *input(const char *ps1, const char *ps2, int (*cb)(char *));

/**
 * Analogs of asprintf() and vasprintf(), except the formatted output is
 * appended to the provided string.
 */
int asprintfa(char **dest, const char *format, ...);
int vasprintfa(char **dest, const char *format, va_list ap);

#endif
