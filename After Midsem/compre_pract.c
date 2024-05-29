#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/**
* @brief Returns the first n words in the file as an array of strings.
*
* Requires: fp points to a file that has at least n words one per line and
each line has at most 80 characters char **words(FILE *fp, int n)
*/
/*char **words(FILE *fp, int n)
{
    char **wds = (char **)malloc(n * sizeof(char *));
    char line[100];
    int count_words = 0;

    if (fgets(line, 100, fp) != NULL)
    {
        int i = 0, j = 0;
        char *word = (char *)malloc(80 * sizeof(char));
        while (count_words < n)
        {
            if (line[i] == ' ')
            {
                word[j] = '\0';
                wds[count_words++] = word;
                j = 0;
                word = (char*)malloc(80*sizeof(char));
            }
            else
                word[j++] = line[i];
            i++;
        }
    }
    return wds;
}

int main()
{
    FILE * fp = fopen("input.txt", "r");
    if (!fp)
    {
        return -1;
    }
    char **wds = words(fp, 8);

    for (int i = 0; i < 8; i++)
    {
        printf("%s\n", wds[i]);
        free(wds[i]);
        wds[i] = NULL;
    }
    free(wds);
    wds = NULL;

    printf("Memory Freed!\n");
    fclose(fp);

    return 0;
}
*/

/*
int main(void)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (abs(4 - i) + abs(4 - j) >= 4)
                printf("*");
            else
                printf("-");
        }
        printf("\n");
    }
}
*/

/*
int main()
{
    char str1[10] = "abc";
    char str2[4] = "de";

    int len = strlen(str1), i;
    for (i = 0; i < strlen(str2); i++)
    {
        str1[i+len] = str2[i];
    }
    str1[i+len] = '\0';

    printf("%s %s\n", str1, str2);
}
*/

/*
int main()
{
    char A[3][3] = {{'a', 'b', '\0'}, {'c', '\0', 'd'}, {'e', 'f', '\0'}};
    char B[9];

    int i = 0, j = 0, k = 0;
    while (i < 3)
    {
        char *row = A[i];
        while (row[j] != '\0')
            B[k++] = row[j++];
        j = 0;
        i++;
    }
    B[k] = '\0';
    printf("%s\n", B);
}
*/

/*
struct str
{
    struct str * a;
    int b[3];
};
typedef struct str str_p;

void func(str_p p)
{
    printf("%p\n", (p.a));
    // printf("%d\n", p.
    printf("%d\n" ,*((p.a)->b) + 2);
    // printf("%d\n" ,*((p.a)->b) + 2);
}

int main()
{
    str_p q = {NULL, {15,3,2}};
    str_p m = {&q, {0,0,0}};
    
    func(m);
}
*/

int main()
{
    int a = 254;
    char b = a;
    printf("%d %d\n", a, b);
    // a << 1;
    // b << 1;
    printf("%d %d\n", a<<24, ~b);
    printf("%d %d\n", ((char)-1)>>1, 4>>3);

}