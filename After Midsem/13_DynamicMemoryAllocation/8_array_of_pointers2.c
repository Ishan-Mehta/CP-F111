#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    char fname[20];
    char id[20];
    double cgpa;
} student_t;

typedef struct
{
    student_t **stud;
    int num;
} class_t;

class_t *get_class_info() 
{
    class_t* c = malloc(sizeof(class_t));
    printf("Enter number of students in a class: ");
    scanf("%d", &c->num);
    c->stud = malloc((c->num) * (sizeof(student_t *)));

    for(int i = 0; i < c->num; i++)
    {
        c->stud[i] = malloc(sizeof(student_t));
        printf("Enter the student's first name, id, and cgpa: ");
        scanf("%s", c->stud[i]->fname);
        scanf("%s", c->stud[i]->id);
        scanf("%lf", &c->stud[i]->cgpa);
    }
    return c;
}

void print_students_info(class_t *class) 
{
    for (int i = 0; i < class->num; i++) 
        printf("%d) %s, %s, %lf\n", i + 1, class->stud[i]->fname, class->stud[i]->id, class->stud[i]->cgpa);
}

int main()
{
    printf("Size of class_t: %d\n", (int)sizeof(class_t));
    printf("sizeof(c): %d", sizeof(class_t));
    // class_t* c = get_class_info();
    printf("You entered:\n");
    // print_students_info(c);
    return 0;
}