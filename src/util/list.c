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

#include <stdlib.h>

#include <util/list.h>

struct list {
    struct list_node *first, *last;
    int count;
};

struct list_node {
    void *value;
    struct list_node *next, *prev;
};

struct list *create_list(void) {
    struct list *l = malloc(sizeof(struct list));
    l->first = NULL;
    l->last = NULL;
    l->count = 0;
    return l;
}

struct list_node *list_append(struct list *l, void *value) {
    struct list_node *n = malloc(sizeof(struct list_node));
    n->value = value;
    n->next = NULL;
    n->prev = l->last;
    if(l->count)
        l->last->next = n;
    else
        l->first = n;
    l->last = n;
    l->count++;
    return n;
}

void *list_remove(struct list *l, struct list_node *n) {
    if(n->prev)
        n->prev->next = n->next;
    else
        l->first = n->next;
    if(n->next)
        n->next->prev = n->prev;
    else
        l->last = n->prev;
    l->count--;
    void *value = n->value;
    free(n);
    return value;
}

struct list_node *list_first(struct list *l) {
    return l->first;
}

struct list_node *list_last(struct list *l) {
    return l->last;
}

int list_count(struct list *l) {
    return l->count;
}

void *list_node_value(struct list_node *n) {
    return n->value;
}

struct list_node *list_node_next(struct list_node *n) {
    return n->next;
}

struct list_node *list_node_prev(struct list_node *n) {
    return n->prev;
}
