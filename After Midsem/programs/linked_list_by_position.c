/*
Linked Lists

+---------+-------+
| name  : _       |
| id    : _       |
| next  : _       |--------------\
+---------+-------+              |
                                 |
+---------+-------+  <-----------/
| name  : _       |
| id    : _       |
| next  : _       |--------------\
+---------+-------+              |
                                 |
+---------+-------+  <-----------/
| name  : _       |
| id    : _       |
| next  : _       |---------->  0 (NULL)
+---------+-------+
*/

#include <stdio.h>
#include <stdlib.h>

struct record
{
    char name[20];
    int id;
    struct record *next;
};

typedef struct record Record;
typedef Record *RecordPtr;

RecordPtr tableStart, tableEnd;

void enterRecord()
{
    RecordPtr user;
    user = (RecordPtr)malloc(sizeof(Record));
    printf("Enter name and id\n");
    scanf("%s", user->name);
    scanf("%d", &(user->id));

    // First entry in the Table
    if (tableStart == NULL)
    {
        printf("Tablestart ----> %s\n", user->name);
        tableStart = user;
        tableEnd = user;
        user->next = NULL;
        return;
    }
    
    printf("Enter position at which the student should be placed (starting from 0) : ");
    int position, count = 0;
    scanf("%d", &position);

    // Entry at the Start:
    // Changing tableStart pointer and user->next arrows
    if (position == 0)
    {
        printf("Tablestart ----> %s\n%s ----> %s\n", user->name, user->name, tableStart->name);
        user->next = tableStart;
        tableStart = user;
        return;
    }

    // Entry in the middle or at the end
    // Traversing through the linked list
    RecordPtr current = tableStart;
    while (count++ < position-1 && current != tableEnd)
        current = current->next;
    
    // pointer reached the end of the table, so updating tableEnd
    if (current == tableEnd)
        tableEnd = user;
    
    // Changing arrows
    user->next = current->next;
    current->next = user;

    printf("%s ----> %s\n%s ----> %s\n", current->name, user->name, user->name, user->next->name);
}

void deleteRecord()
{
    RecordPtr current = tableStart;
    int position, count = 0;
    printf("Enter the position of the student to be deleted (0 being the 1st): ");
    scanf("%d", &position);

    // Deleting the entry at position 0 (if exists)
    if (position == 0 && tableStart != NULL)
    {
        printf("Tablestart --X--> %s\nTablestart ----> %s\n", tableStart->name, tableStart->next->name);
        current = tableStart->next;
        free(tableStart);
        tableStart = current;
        return;
    }

    // Deleting in the middle or at the end
    // Traversing through the linkedlist
    while (count++ < position-1 && current != tableEnd)
        current = current->next;

    // Returning if there are not enough entries in the table to traverse further
    if (tableEnd == current)
    {
        printf("No entry registered yet at position %d\n", position);
        return;
    }

    // Deleting the entry at given position
    printf("%s --X--> %s ----> %s\n%s ----> %s\n", current->name, current->next->name, current->next->next->name, current->name, current->next->next->name);
    RecordPtr child_node_of_to_be_deleted = current->next->next;
    free(current->next);
    current->next = child_node_of_to_be_deleted;
}

void printTable()
{
    RecordPtr x;
    x = tableStart;
    printf("The list is : \n");
    while (x != NULL)
    {
        printf("name : %s, id : %d\n", x->name, x->id);
        x = x->next;
    }
}

void freeList(RecordPtr current)
{
    printf("Freeing: Name: %s, id: %d\n", current->name, current->id);
    if (current->next != NULL)
        // Freeing the farthest node first and then traversing back using recursion
        freeList(current->next);

    printf("Freed: Name: %s, id: %d\n", current->name, current->id);
    // Freeing the node and returning the parent node
    free(current);
    current = NULL;
}

int main()
{
    tableStart = NULL;
    tableEnd = NULL;

    while (1)
    {
        char option;
        printf("Do you want to\n\t1. Insert (Enter 'I')\n\t2. Delete (Enter 'D')\n\t3. Print (Enter 'P')\n\t4. Exit (Enter 'E') : ");
        scanf(" %c", &option);

        switch (option)
        {
        case 'I': case 'i': case '1':
            enterRecord();
            break;
        case 'D': case 'd': case '2':
            deleteRecord();
            break;
        case 'P': case 'p': case '3':
            printTable();
            break;
        }
        if (option == 'E' || option == 'e' || option == '4')
            break;
    }

    // Freeing memory (only if exists)
    if (tableStart != NULL)
    {
        printf("Freeing Memory...\n");
        freeList(tableStart);
    }
    tableStart = NULL;
    tableEnd = NULL;

    return 0;
}
