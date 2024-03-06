#include<stdio.h>

void PrintArray(char arr[], int n)  //Function to print the array. Do not change this
{
    for(int i=0;i<n;i++)
    {
        printf("%c",arr[i]);
    }
    printf("\n");
}

int main()
{
    char name[20], surname[20];
    scanf("%s %s", name, surname);

    printf("%s + %s\n", name, surname);

    
    char str[6] = {'I', 'S', 'H', 'A', 'N'};
    char str2[3] = {'q', 'w', 'e', 'r', 't'};
    char str3[] = {'p', 'o', 'i', 'u', 'y'};
    char str4[] = "iShAn";
    char str5[5] = "36482";
    char str6[6] = "d34g5";
    char str7[8] = "IShaN";

    printf("str: %s\n", str);
    PrintArray(str, 10);
    printf("str2: %s\n", str2);
    PrintArray(str2, 10);
    printf("str3: %s\n", str3);
    PrintArray(str3, 10);
    printf("str4: %s\n", str4);
    PrintArray(str4, 10);
    printf("str5: %s\n", str5);
    PrintArray(str5, 10);
    printf("str6: %s\n", str6);
    PrintArray(str6, 10);
    printf("str7: %s\n", str7);
    PrintArray(str7, 10);


}