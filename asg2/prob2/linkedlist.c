#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

node_t *create_node(void *data)
{
    node_t *new = (node_t *)malloc(sizeof(node_t));
    new->data = data;
    new->next = NULL;
    return new;
}

void insert_at_begin(node_t **head, void *data)
{
    node_t *new = create_node(data);
    new->next = *head;
    *head = new; 
}

void insert_at_end(node_t **head, void *data)
{
    node_t *new = create_node(data);
    if(*head == NULL) {
        *head = new;
        return;
    }
    node_t *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
}

void delete_node(node_t **head, void *data)
{
    node_t *temp = *head;
    node_t *prev = NULL;

    // If head node itself holds the data to delete
    if (temp != NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    
    // If data to delete was not present in list
    if (temp == NULL) return;
    
    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp);  
}

void print_all_node(node_t *head, callback_print cb)
{
    node_t *temp = head;
    while (temp != NULL)
    {
        cb(temp);
        temp = temp->next;
    }
    printf("\n");
}

void delete_ll(node_t *head)
{
    node_t *temp = head;
    node_t *prev;
    while (temp != NULL)
    {
        prev = temp;
        temp = temp->next;
        free(prev->data);
        free(prev);
    }
}

node_t* find_node(node_t *head, callback_find cb, void *value)
{
    node_t *temp = head;
    while (temp != NULL)
    {
        if(cb(temp, value)) {
            return temp;
        } 
        else {
            temp = temp->next;
        } 
    }
    return NULL;
}

static void sorted_insert(node_t **head, node_t *new_node, compare_left_right cb) {
    node_t *current;

    if (*head == NULL || cb((*head)->data, new_node->data)) {
        new_node->next = *head;
        *head = new_node;
    } else {
        current = *head;
        while (current->next != NULL && cb(new_node->data, current->next->data)) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void insertion_sort(node_t **head, compare_left_right cb) {
    node_t *sorted = NULL;

    node_t *current = *head;
    while (current != NULL) {
        node_t *next = current->next;
        sorted_insert(&sorted, current, cb);
        current = next;
    }
    *head = sorted; 
}