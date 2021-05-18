#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#define ll long long
#define PI 3.14159265
#define br printf("\n")
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define file_read                     \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
int MOD = 1e9 + 7;
typedef char elementtype;
typedef struct node node;
typedef struct node *ptrnode;

struct node
{
    elementtype data;
    ptrnode next;
    ptrnode rear;
    ptrnode prev;
};

void push_front(ptrnode p, elementtype data); // Insert at front
ptrnode createnode(elementtype data);
void pop(ptrnode p);                         // Remove from front
void push_back(ptrnode p, elementtype data); // Insert at Rear
void eject(ptrnode p);                       // Remove item from rear
bool empty(ptrnode p);                       // Return whether the Queue is empty or not
int size(ptrnode p);                         // Return The size of Queue
elementtype front(ptrnode p);                // Return the first element of the queue
elementtype back(ptrnode p);                 // Return the last element of the queue

elementtype back(ptrnode p)
{
    return p->rear->data;
}

elementtype front(ptrnode p)
{
    return p->next->data;
}

int size(ptrnode p)
{
    int c = 0;
    while (p->next != NULL)
    {
        p = p->next;
        c++;
    }
    return c;
}

bool empty(ptrnode p)
{
    if (p->next == NULL)
    {
        return true;
    }
    else
        return false;
}

void push_front(ptrnode p, elementtype e)
{
    ptrnode pnew = createnode(e);
    if (p->next == NULL)
    {
        p->rear = pnew;
    }
    else
    {
        p->next->prev = pnew;
    }
    pnew->next = p->next;
    p->next = pnew;
    pnew->prev = p;
}

ptrnode createnode(elementtype e)
{
    ptrnode p = (ptrnode)malloc(sizeof(node));
    assert(p != NULL);
    p->data = e;
    p->next = NULL;
    p->prev = NULL;
    p->rear = NULL;
    return p;
}

void pop(ptrnode p)
{
    if (p->next != NULL)
    {
        if (p->next->next == NULL)
        {
            p->rear = p;
        }
        ptrnode temp = p;
        temp->next = p->next;
        temp = temp->next;
        p->next = temp->next;
        free(temp);
    }
}

void push_back(ptrnode p, elementtype e)
{

    ptrnode pnew = createnode(e);
    if (p->rear == NULL)
    {
        pnew->prev = p;
        p->next = pnew;
    }
    else
    {
        pnew->prev = p->rear;
        p->rear->next = pnew;
    }
    p->rear = pnew;
}

void eject(ptrnode p)
{
    if (p->rear != NULL)
    {
        ptrnode temp = p->rear;
        temp->prev->next = NULL;
        if (temp->prev != p)
            p->rear = temp->prev;
        else
        {
            p->rear = NULL;
        }
        free(temp);
    }
}

int main()
{
    char str[100001];
    scanf("%s", str);
    char array[strlen(str)]; // This array will store the minimum character of each suffix
    ll leng = strlen(str);
    array[0] = str[leng - 1];
    ll pos = leng - 2;
    char ch;
    for (int i = 1; i < leng; i++)
    {
        ch = str[pos];
        if (ch < array[i - 1])
        {
            array[i] = ch;
        }
        else
        {
            array[i] = array[i - 1];
        }
        pos--;
    }
    int i = 0;
    ptrnode s;
    s = createnode(0);
    fo(i, leng)
    {
        if (array[leng - i - 1] == str[i])
        {
            printf("%c", str[i]);
        }
        else
        {
            push_front(s, str[i]);
        }
    }
    while (!empty(s))
    {
        char ch = front(s);
        pop(s);
        printf("%c", ch);
    }
    br;
    return 0;
}