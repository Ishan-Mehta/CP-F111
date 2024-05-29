#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int findPalindromeLen(char *smallest_name, int start_index, int end_index, int minLength)
{
    while (start_index >= 0 && end_index < minLength && smallest_name[start_index] == smallest_name[end_index])
    {
        start_index--;
        end_index++;
    }

    return end_index - start_index - 1;
}

char* longestPalindrome(char* smallest_name) {
    int minLength = strlen(smallest_name), longest_palind_len = 0;
    
    if (minLength == 1)
        return smallest_name;
    
    char longest_palind[minLength+1];
    printf("%d\n", minLength);

    for (int i = 1; i < minLength - 1; i++)
    {
        printf("%c\n", smallest_name[i]);
        int start_index, end_index = i + 1; // end_index = i + 1

        if ((smallest_name[(start_index = i)] == smallest_name[end_index] || smallest_name[(start_index = i - 1)] == smallest_name[end_index]) || (start_index=i) == (end_index=i))
        {
            int current_palind_len = findPalindromeLen(smallest_name, start_index, end_index, minLength); // end_index - start_index - 1;
            char current_palind[current_palind_len + 1];
            
            start_index = i - (current_palind_len / 2);
            if (current_palind_len % 2 == 0)
                start_index += 1;
            
            strncpy(current_palind, smallest_name+start_index, current_palind_len);
            current_palind[current_palind_len] = '\0';

            if (current_palind_len > longest_palind_len)
            {
                strcpy(longest_palind, current_palind);
                longest_palind_len = current_palind_len;
            }
            printf("%s\n", longest_palind);
        }
        printf("i: %d\n", i);
    }

    printf("hello");
    strcpy(smallest_name, longest_palind);
    printf("hellosadas");


    return smallest_name;
}


int main()
{
    char *s = "asdasBADABgrenm";

    char *ss = longestPalindrome(s);
    printf("%s\n", ss);

    return 0;
}