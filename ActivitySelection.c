#include<stdio.h>
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void ActivitySelection(int F[], int S[], int A[], int n)
{
    int i, j, k, l;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
            {
                if (F[j] > F[j + 1])
                {
                    swap(&F[j], &F[j + 1]);
                    swap(&A[j], &A[j + 1]);
                    swap(&S[j], &S[j + 1]);
                }
            }
    }
    printf("Following activities are selected\n");
    k = 0;
    printf("%d ", A[k]);
    for (l = 1; l < n; l++)
    {
        if (S[l] >= F[k])
        {
            printf("%d ", A[l]);
            k = l;
        }
    }
}

int main()
{
    int S[100], F[100], A[100], n, i;
    printf("\nHARSH VIKAS SHETYE_60009210068\n\n");
    printf("Enter the number of array elements ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        A[i]=i+1;
        printf("Enter the corresponding elements in S and F ");
        scanf("%d %d", &S[i], &F[i]);
    }
    ActivitySelection(F, S, A, n);
    return 0;
}
