// TWO SUBSTRINGS
#include <stdio.h>
#include <string.h>
int main()
{
    char str[100000];
    for (int i = 0; i < 100000; i++)
    {
        str[i] = '\0';
    }
    int i = 0;
    char ch;
    while ((ch = getchar()) != '\n')
    {
        str[i] = ch;
        i++;
    }
    int c;
    for (int i = 0; i < strlen(str); i++)
    {
        for (int j = 0; j < strlen(str); j++)
        {
            if ((str[i] == 'A' && str[i + 1] == 'B' && i < (strlen(str) - 1)) && (str[j] == 'B' && str[j + 1] == 'A' && j < (strlen(str) - 1)) && i + 1 != j)
            {
                c = 1;
            }
        }
    }
    if (c == 1)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}
