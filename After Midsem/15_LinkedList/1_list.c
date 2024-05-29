/*
Linked Lists

+---------+-------+
+ name  : _       +
+ id    : _       +
+ next  : _       +  ------------+
+---------+-------+              +
                                 +
+---------+-------+  <-----------+
+ name  : _       +
+ id    : _       +
+ next  : _       +  ------------+
+---------+-------+              +
                                 +
+---------+-------+  <-----------+
+ name  : _       +
+ id    : _       +
+ next  : _       +  -------->  0
+---------+-------+
*/



#include <stdio.h>
#include <stdlib.h>

struct record{
  char name[20];
  int id;
  struct record *next;
};

typedef struct record Record;
typedef Record * RecordPtr;

RecordPtr tableStart, tableEnd;

void enterRecord()
{
    RecordPtr user;
    user = (RecordPtr) malloc(sizeof(Record));
    printf("Enter name and id\n");
    scanf("%s",user->name);
    scanf("%d",&(user->id));
    user->next = 0;

    if (tableStart == 0)
    {
        tableStart = user;
        tableEnd = user;
    }
    else
    {
        tableEnd->next = user;
        tableEnd = user;
    }
}

void printTable()
{
    RecordPtr x;
    x=tableStart;
    printf("The list is : \n");
    while(x!=0)
    {
        printf("name : %s, id : %d\n", x->name, x->id);
        x=x->next;
    }
}


int main()
{
    tableStart=0;
    tableEnd=0;

    char option;
    while(1)
    {
        enterRecord();
        printf("Do you want to continue? (Y/N)\n");
        scanf(" %c",&option);
        if (option == 'N' || option == 'n')
        {
            printTable();
            break;
        }
    }
    return 0;
}
