#ifndef __UTIL_LIST_H__
#define __UTIL_LIST_H__

/**
 * A doubly-linked list of generic pointers.
 */
struct list;
struct list_node;

/**
 * Create a new list.
 */
struct list *create_list(void);

/**
 * Append the given value to the list.
 */
struct list_node *list_append(struct list *l, void *value);

/**
 * Remove the given node from the list, and return its value.
 */
void *list_remove(struct list *l, struct list_node *n);

/**
 * Get the first node in the list.
 */
struct list_node *list_first(struct list *l);

/**
 * Get the last node in the list.
 */
struct list_node *list_last(struct list *l);

/**
 * Get the number of nodes in the list.
 */
int list_count(struct list *l);

/**
 * Get the value of the given node.
 */
void *list_node_value(struct list_node *n);

/**
 * Get the node following this node.
 */
struct list_node *list_node_next(struct list_node *n);

/**
 * Get the node preceding this node.
 */
struct list_node *list_node_prev(struct list_node *n);

#endif
