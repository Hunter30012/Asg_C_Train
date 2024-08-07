#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
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
    float temp;
    do
    {
        printf("The number of employees: ");
        scanf("%f", &temp);
    } while (temp > 50 || temp < 0 || (temp - (int)temp) != 0);
    *n = temp;
    
    for(int i = 0; i < *n; i++) {
        employee_t* emp = (employee_t *)malloc(sizeof(employee_t));
        printf("\nInput the information of employee %d: \n", i+1);

        printf("Enter employee ID: ");
        scanf("%u", &emp->id);
        while (getchar() != '\n');

        printf("Enter full name: ");
        fgets(emp->fullname, sizeof(emp->fullname), stdin);
        emp->fullname[strcspn(emp->fullname, "\n")] = '\0';

        printf("Enter department: ");
        fgets(emp->department, sizeof(emp->department), stdin);
        emp->department[strcspn(emp->department, "\n")] = '\0';

        printf("Enter salary: ");
        scanf("%u", &emp->salary);
        while (getchar() != '\n');

        printf("Enter start date (dd/mm/yyyy): ");
        fgets(emp->start_date, sizeof(emp->start_date), stdin);
        emp->start_date[strcspn(emp->start_date, "\n")] = '\0';

        insert_at_end(head, (void *)emp);      
    }

}

static bool find_employee_id(node_t *node, void *value)
{
    employee_t *emp = (employee_t* )node->data;
    uint32_t id = *(uint32_t*)value;
    if(emp->id == id) {
        return true;
    }
    return false;
}

static bool find_employee_fullname(node_t *node, void *value)
{
    employee_t *emp = (employee_t* )node->data;
    char *full = (char *)value;
    if(strcmp(emp->fullname, full) == 0) {
        return true;
    }
    return false;
}

void remove_employee(node_t **head, type_delete_t type)
{
    node_t *temp;
    switch (type)
    {
    case ID:
        uint32_t id;
        printf("Enter ID to delete: ");
        scanf("%u", &id);
        while (getchar() != '\n');
 
        temp = find_node(*head, find_employee_id, (void *)&id);
        if(temp != NULL) {
            delete_node(head, temp->data);        
        }
        break;
    
    case FULL_NAME:
        char fullname[30];
        printf("Enter full name to delete: ");
        fgets(fullname, sizeof(fullname), stdin);
        fullname[strcspn(fullname, "\n")] = '\0';  

        do {
            temp = find_node(*head, find_employee_fullname, (void *)fullname);
            if(temp != NULL) {
                delete_node(head, temp->data);        
            }
        } while(temp != NULL);
        break;

    default:
        break;
    }
}

static void print_employee(node_t *node)
{
    employee_t *emp = (employee_t* )node->data;
    printf("%-10s %-30s %-10s %-20s %-12s\n", "ID", "Full Name", "Dept", "Salary", "Start Date");
    printf("----------------------------------------------------------------------------------------\n");
    printf("%-10u %-30s %-10s %-20u %-12s\n", emp->id, emp->fullname, emp->department, emp->salary, emp->start_date);
}

static bool compare_left_bigger_right(void *left, void* right)
{
    employee_t *emp_1 = (employee_t *) left;
    employee_t *emp_2 = (employee_t *) right;
    if(emp_1->salary > emp_2->salary) {
        return true;
    }
    return false;
}

static bool compare_left_smaller_right(void *left, void* right)
{
    employee_t *emp_1 = (employee_t *) left;
    employee_t *emp_2 = (employee_t *) right;
    if(emp_1->salary < emp_2->salary) {
        return true;
    }
    return false;
}



int main(int argc, char **argv)
{
    node_t *head = NULL;
    int number_emp;
    int selection;

    while (1)
    {
        printf("\nMenu to manager employee. Please enter option: \n");
        printf("1. Enter information\n");
        printf("2. Delete employee\n");
        printf("3. Sort salary of employees\n");
        printf("4. Print all information of employees\n");
        printf("5. Exit\n");
        scanf("%d", &selection);
        while (getchar() != '\n');
        switch (selection)
        {
            case 1:
                input_info(&head, &number_emp);
                break;
            case 2:
                int op2;
                printf("Select option: 1 - ID; 2 - Fullname\n");
                scanf("%d", &op2);
                while (getchar() != '\n');
                if(op2 == 1) {
                    remove_employee(&head, ID);
                }
                else if(op2 == 2) {
                    remove_employee(&head, FULL_NAME);
                }
                break;
            case 3:
                int op3;
                printf("Select option: 1 - Ascending; 2 - Descending\n");
                scanf("%d", &op3);
                while (getchar() != '\n');
                if(op3 == 1) {
                    insertion_sort(&head, compare_left_bigger_right);
                    print_all_node(head, print_employee);
                }
                else if(op3 == 2) {
                    insertion_sort(&head, compare_left_smaller_right);
                    print_all_node(head, print_employee);
                }
                break;
            case 4:
                print_all_node(head, print_employee);
                break;
            case 5:
                delete_ll(head);
                return 0;
                break;
            default:
                printf("Enter option again\n");
                break;
        }
    }
}