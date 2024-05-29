#include <stdio.h>
/*
struct bowler
{
    char name[20];
    char country_code[4];
    int wickets;
    int num_5wkts;
};

typedef struct bowler bowl;
*/
typedef struct bowler
{
    char name[20];
    char country_code[4];
    int wickets;
    int num_5wkts;
}bowl;

void display(bowl* b)
{
    printf("Bowler Name: %s\n", b->name);
    printf("Country: %s\n", (*b).country_code);
    printf("Number of Wickets: %d\n", (*b).wickets);
    printf("Number of 5-Wicket hauls: %d\n\n", (*b).num_5wkts);
}

//Arrow operator (->) is another way to access structure fields/members using pointer to the structure variable.
//ptr –> member is the same as (*ptr).member
bowl* more_wickets(bowl *b1, bowl *b2)
{
    bowl* b = (b1 -> wickets > b2 -> wickets) ? (b1) : (b2);
    return b;
}

int main()
{
    bowl b1 = {"Kallis", "SA", 577, 7};
    bowl b2 = {"Bumrah", "IND", 319, 10};

    printf("Size of bowl = %lu\n\n", sizeof(b1));

    display(&b1);
    display(&b2);

    bowl *b = more_wickets(&b1,&b2);
    printf("%s took more wickets\n", b->name);

    return 0;
}