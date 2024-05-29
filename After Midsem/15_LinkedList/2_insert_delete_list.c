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
+ next  : _       +  -------->  NULL
+---------+-------+
*/



#include <stdio.h>
#include <stdlib.h>

typedef struct record{
  char name[20];
  int id;
  struct record *next;
}Record;

typedef Record * RecordPtr;

RecordPtr head;

void enterRecord()
{
    RecordPtr user;
    user = (RecordPtr) malloc(sizeof(Record));
    printf("Enter name and id\n");
    scanf("%s",user->name);
    scanf("%d",&(user->id));
    user->next = NULL;

    if (head == NULL)
    {
        head = user;
    }
    else
    {
        RecordPtr tail = head;
        while(tail -> next != NULL)
            tail = tail -> next;
        tail->next = user;
    }
}

void printTable()
{
    RecordPtr x;
    x=head;
    printf("The list is: \n");
    while(x!=NULL)
    {
        printf("name : %s, id : %d\n", x->name, x->id);
        x=x->next;
    }
}

void insert_at_head()
{
    RecordPtr user;
    user = (RecordPtr) malloc(sizeof(Record));
    printf("Enter name and id\n");
    scanf("%s",user->name);
    scanf("%d",&(user->id));
    user->next = head;
    head = user;
}

void insert_in_middle()
{
    RecordPtr user;
    user = (RecordPtr) malloc(sizeof(Record));
    printf("Enter name and id\n");
    scanf("%s",user->name);
    scanf("%d",&(user->id));
    int insert_id;
    printf("Enter the predecessor ID (that is the ID you want before %d)", user->id);
    scanf("%d", &insert_id);

    RecordPtr x = head;
    while(x->id != insert_id)
        x = x -> next;
    user->next = x->next;
    x->next = user;
}

void delete(int delete_id)
{
    RecordPtr x = head;

    if(x->id == delete_id) //Delete at head
    {
        head = x->next;
        free(x);
    }
    else 
    {
        while((x->next->id != delete_id) && (x->next!=NULL))
            x = x -> next;

        if(x->next == NULL)
            printf("No such ID found\n");

        else if(x->next->id == delete_id)
        {
            RecordPtr y = x->next;
            x->next = y->next;
            free(y);
        }
    }
}

int main()
{
    head = NULL;

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

    int opt;
    while(1)
    {
        printf("Where do you want to insert a record?\n");
        printf("1. At the start, 2. Afterwards, 3. exit: ");
        scanf("%d", &opt);

        if(opt == 1)
            insert_at_head();
        else if(opt == 2)
            insert_in_middle();
        else
            break;   
        printTable();
    }

    int id;
    while(1)
    {
        printf("Which record do you want to delete? Enter ID: ");
        scanf("%d", &id);
        delete(id);  
        printTable();
        printf("Do you want to delete more (y/n)? ");
        scanf(" %c",&option);
        if (option == 'N' || option == 'n')
            break;
    }

    return 0;
}
