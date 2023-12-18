#include <stdio.h>
#include <stdlib.h>
#define N 100
int stack[N];
int top=-1;

void Push(int val)
{
    top++;
    stack[top]=val;
}

int Pop()
{
    int x= stack[top];
    top--;
    return x;
}

int main()
{
    int arr[5], rra[5];
    printf("Enter a list of 5:\n");
    for(int i=0; i<5; i++)
    scanf("%d", &arr[i]);
    for(int i=0; i<5; i++)
    Push(arr[i]);
    for(int i=0; i<5; i++)
    rra[i]= Pop();
    printf("Reverse list:\n");
    for(int i=0; i<5; i++)
    printf("%d\n", rra[i]);
    return 0;
}