#include <stdio.h>
#include <stdlib.h>

typedef struct bowler
{
    char name[20];
    char country_code[4];
    int wickets;
    int num_5wkts;
}bowl;

void display(bowl* b)
{
    printf("Bowler Name: %s\n", (*b).name);
    printf("Country: %s\n", (*b).country_code);
    printf("Number of Wickets: %d\n", (*b).wickets);
    printf("Number of 5-Wicket hauls: %d\n\n", (*b).num_5wkts);
}
/*
//Will not work
bowl* more_wickets(bowl *b1, bowl *b2)
{
    bowl b = (b1 -> wickets > b2 -> wickets) ? (*b1) : (*b2);
    return &b;
}
*/

bowl* more_wickets(bowl *b1, bowl *b2)
{
    bowl *b = (bowl*) malloc(sizeof(bowl));
    *b = (b1 -> wickets > b2 -> wickets) ? *b1 : *b2;
    return b;
}

int main()
{
    bowl b1 = {"Kallis", "SA", 577, 7};
    bowl b2 = {"Bumrah", "IND", 319, 10};

    printf("Size of bowl = %d\n\n", (int)sizeof(b1));

    display(&b1);
    display(&b2);

    bowl *b = more_wickets(&b1,&b2);
    printf("%s took more wickets\n", b->name);

    free(b);
    b = NULL;//Good Practice
    return 0;
}