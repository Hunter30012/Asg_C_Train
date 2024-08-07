#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <stdbool.h>

typedef struct _node
{
    void *data;
    struct _node *next;
} node_t;

typedef void (*callback_print)(node_t *);
typedef bool (*callback_find)(node_t *, void *);
typedef bool (*compare_left_right)(void *, void *);

node_t * create_node(void *data);

void insert_at_begin(node_t **head, void *data);

void insert_at_end(node_t **head, void *data);

void delete_node(node_t **head, void *data);

void print_all_node(node_t *head, callback_print cb);

void delete_ll(node_t *head);

node_t * find_node(node_t *head, callback_find cb, void *value);

void insertion_sort(node_t **head, compare_left_right);

#endif