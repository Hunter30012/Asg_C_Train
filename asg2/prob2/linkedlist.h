#ifndef __LINKED_LIST__
#define __LINKED_LIST__

typedef struct _node
{
    void *data;
    struct _node *next;
} node_t;

typedef void (*callback_print)(node_t *arg);

node_t * create_node(void *data);

void insert_at_begin(node_t **head, void *data);

void insert_at_end(node_t **head, void *data);

void delete_node(node_t **head, void *data);

void print_all_node(node_t *head, callback_print cb);

void delete_ll(node_t *head);

#endif