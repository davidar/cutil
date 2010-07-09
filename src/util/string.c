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

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include <util/string.h>

int streq(const char *s1, const char *s2) {
    return strcmp(s1, s2) == 0;
}

int starts_with(const char *s, const char *prefix) {
    return memcmp(s, prefix, strlen(prefix)) == 0;
}

int ends_with(const char *s, const char *suffix) {
    return memcmp(s + strlen(s) - strlen(suffix), suffix, strlen(suffix)) == 0;
}

int contains_string(const char **array, const char *s) {
    while(*array)
        if(strcmp(*array++, s) == 0)
            return 1;
    return 0;
}

int string_in(const char *s, ...) {
    va_list ap; va_start(ap, s);
    const char *e;
    while((e = va_arg(ap, const char *)))
        if(strcmp(s, e) == 0)
            break;
    va_end(ap);
    return e != NULL;
}

char *split(char *s) {
    while(*s && !isspace(*s))
        s++;
    if(*s) {
        *s++ = 0;
        while(isspace(*s))
            s++;
    }
    if(!*s)
        s = NULL;
    return s;
}

char *astrcat(char **dest, const char *src) {
    *dest = realloc(*dest, strlen(*dest) + strlen(src) + 1);
    strcat(*dest, src);
    return *dest;
}

char *astrcatf(char **dest, char *src) {
    astrcat(dest, src);
    free(src);
    return *dest;
}

void ltrim(char **s) {
    while(isspace(**s))
        (*s)++;
}

void rtrim(char **s) {
    for(char *p = *s + strlen(*s) - 1; p >= *s && isspace(*p); p--)
        *p = 0;
}

void trim(char **s) {
    ltrim(s);
    rtrim(s);
}

char *strchrr(char *s, char c, char z) {
    char *p = strchr(s, c);
    if(p) *p = z;
    return p;
}
