#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubblesort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}
int teams(int n, int x, int arr[], int res, int people)
{
    bubblesort(arr, n);
    for (int i = 0; i < n; i++)
    {
        if ((i + 1 - people) * arr[n - i - 1] >= x)
        {
            res++;
            people = i + 1;
            if (n - i - 1 > 0)
            {
                teams(n - i - 1, x, arr, res, people);
            }
        }
    }
    return res;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, x, people = 0;
        int res = 0;
        scanf("%d %d", &n, &x);
        int a[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        res = teams(n, x, a, res, people);
        printf("%d\n", res);
    }

    return 0;
}