#include<stdio.h>


int main()
{
    // EOF (-1)

    FILE *fp; 

    if(!(fp = fopen("input.txt", "a+")))
    {
        printf("Open nhi hua\n");
        return -1;
    }

    // int c = fgetc(fp);
    // fputc(c, fp);

    int ch1, ch2;
    fseek(fp, 0, SEEK_SET);
    while ((ch1 = fgetc(fp)) != EOF)
    {
        printf("%c", ch1);
        printf("before :: position: %ld\n", ftell(fp));
        fputc(ch1, fp);
        printf("after :: position: %ld\n", ftell(fp));
    }
    


    /*int num, sum = 0;
    while (fscanf(fp, "%d", &num) != EOF)
    {
        printf("Number found: %d\n", num);
        sum += num;
    }
    printf("Sum: %d\n", sum);*/
    

    fclose(fp);
    
    return 0;
}