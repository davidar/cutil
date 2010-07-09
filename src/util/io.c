/*
* Copyright (c) 2010 David A Roberts <d@vidr.cc>
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <util/io.h>
#include <util/string.h>

#define INIT_BUF_SIZE 64

char *read_line(FILE *fp) {
    int buf_size = INIT_BUF_SIZE;
    char *buf = calloc(buf_size, sizeof(char)); *buf = 0;
    int tail_size = buf_size;
    char *tail = buf;

    /* successively read portions of the line into the tail of the buffer
     * (the empty section of the buffer following the text that has already
     * been read) until the end of the line is encountered */
    while(!feof(fp)) {
        if(fgets(tail, tail_size, fp) == NULL) {
            /* EOF or read error */
            free(buf);
            return NULL;
        }
        if(tail[strlen(tail)-1] == '\n') {
            /* end of line reached */
            break;
        }
        /* double size of buffer */
        tail_size = buf_size + 1; /* size of new tail */
        buf_size *= 2; /* increase size of buffer to fit new tail */
        buf = realloc(buf, buf_size * sizeof(char));
        tail = buf + buf_size - tail_size; /* point tail at null-terminator */
    }
    tail[strlen(tail)-1] = 0; /* remove trailing newline */
    return buf;
}

char *input(const char *ps1, const char *ps2, int (*cb)(char *)) {
    printf("%s", ps1); fflush(stdout);
    char *line = read_line(stdin);
    if(line == NULL)
        return NULL;
    while(cb && cb(line)) {
        printf("%s", ps2); fflush(stdout);
        char *s = read_line(stdin);
        if(s == NULL) {
            free(line);
            return NULL;
        }
        astrcat(&line, "\n");
        astrcatf(&line, s);
    }
    return line;
}

int asprintfa(char **dest, const char *format, ...) {
    va_list ap; va_start(ap, format);
    int res = vasprintfa(dest, format, ap);
    va_end(ap);
    return res;
}

int vasprintfa(char **dest, const char *format, va_list ap) {
    char *out;
    int res = vasprintf(&out, format, ap);
    astrcatf(dest, out);
    return res;
}
