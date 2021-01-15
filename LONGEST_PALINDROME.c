#include <stdio.h>
#include <string.h>
int isPalindrome(char str[])
{
    int l = 0;
    int c = 0; // counter
    int h = strlen(str) - 1;
    while (h > l)
    {
        if (str[l++] != str[h--])
        {
            c++;
        }
    }
    if (c == 0)
        return 1; // It is palindrome
    else
        return 0; // Not palindrome
}
int main()
{
    int n, m, c, len, max_len = 0;
    scanf("%d %d", &n, &m);
    char str[n][m+1];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", str[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            strcpy(temp, strcat(str[i], str[j]));
            printf("i = %d;j = %d\n", i, j);
            printf("%s\n", temp);
            /*c = isPalindrome(temp);
            if (c == 1)
            {
                len = strlen(temp);
                if (len >= max_len)
                {
                    max_len = len;
                }
            }*/
        }
    }
    /*if (max_len == 0)
        printf("0");
    else
    {
        printf("%d", max_len);
        printf("%s", temp);
    }*/
    return 0;
}