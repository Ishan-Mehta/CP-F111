#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int id;
    struct node * next;
} Record;


void insert(Record * tableStart, Record *x)
{
    if (tableStart == NULL || x->id < tableStart->id)
    {
        x->next = tableStart;
        tableStart = x;
        printf("head: id: %d\n", tableStart->id);
        return;
    }

    Record * curr = tableStart;
    printf("head: id: %d\n", curr->id);

    while (curr->next != NULL && x->id > curr->next->id)
    {
        printf("before id: %d\n", curr->id);
        curr = curr->next;
        printf("after id: %d\n", curr->id);
    }

    printf("last before id: %d\n", curr->id);
    x->next = curr->next;
    curr->next = x;
    printf("last after id: %d\n", curr->id);
    printf("last after next id: %d\n", curr->next->id);
}


void printTable(Record * tableStart)
{
    Record *x;
    x=tableStart;
    printf("The list is : \n");
    while(x!=0)
    {
        printf("id : %d\n",x->id);
        x=x->next;
    }
}


int main()
{
    Record node1 = {1, NULL};
    Record * head = &node1;

    Record node2 = {3, NULL};
    node1.next = &node2;

    Record entry = {2, NULL};
    insert(head, &entry);

    printTable(head);
}