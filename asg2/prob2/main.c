#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "linkedlist.h"

typedef enum {
    ID,
    FULL_NAME
} type_delete_t;

typedef struct _employee
{
    uint32_t id;
    char fullname[30];
    char department[10];
    uint32_t salary;
    char start_date[12];
} employee_t;

void input_info(node_t **head, int *n)
{
    do
    {
        printf("The number of employees: ");
        scanf("%d", n);   
    } while (*n > 50);


}

void remove_employee()
{

}

void print_employee(node_t *node)
{
    employee_t *emp = (employee_t* )node->data;
    printf("%-10s %-30s %-10s %-10s %-12s\n", "ID", "Full Name", "Dept", "Salary", "Start Date");
    printf("----------------------------------------------------------------------------------\n");
    printf("%-10u %-30s %-10s %-10u %-12s\n", emp->id, emp->fullname, emp->department, emp->salary, emp->start_date);
}

int main(int argc, char **argv)
{

}