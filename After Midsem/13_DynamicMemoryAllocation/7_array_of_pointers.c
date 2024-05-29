#include<stdio.h>
#include<stdlib.h>

typedef struct student
{
    char fname[20];
    char id[20];
    double cgpa;
} student_t;

student_t *get_student_info() 
{
    student_t *s = (student_t *)malloc(sizeof(student_t));
    printf("Size of student_t = %lu\n", sizeof(student_t));
    printf("Enter the student's first name, id, and cgpa: ");
    scanf("%s", s->fname);
    scanf("%s", s->id);
    scanf("%lf", &s->cgpa);
    return s;
}

void print_students_info(student_t *students[], int length) 
{
    for (int i = 0; i < length; i++) 
    {
        student_t *s = students[i];
        printf("%d) %s, %s, %lf\n", i + 1, s->fname, s->id, s->cgpa);
    }
}

int main()
{
    student_t *student_info[100];
    int student_count = 0; 
    char response[2];
    printf("Do you want to enter a student's info? (y/n) ");
    scanf("%s", response);
    
    while (response[0] == 'y') 
    {
        student_info[student_count++] = get_student_info();
        printf("Do you want to enter a student's info? (y/n) ");
        scanf("%s", response);
    }
    printf("You entered:\n");
    print_students_info(student_info, student_count);
    return 0;
}