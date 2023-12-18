#include <stdio.h>

void findSubsets(int set[], int n, int sum, int subset[], int count, int start)
{
    if (sum == 0)
    {
        printf("{ ");
        for (int i = 0; i < count; i++)
        {
            printf("%d ", subset[i]);
        }
        printf("}\n");
        return;
    }
    for (int i = start; i < n; i++)
    {
        if (set[i] <= sum)
        {
            subset[count] = set[i];
            findSubsets(set, n, sum - set[i], subset, count + 1, i + 1);
        }
    }
}
int main()
{
    int n, sum;
    printf("\nHarsh Shetye_60009210068_Sum of Subsets\n");
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int set[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &set[i]);
    }
    printf("Enter the target sum: ");
    scanf("%d", &sum);
    int subset[n];
    findSubsets(set, n, sum, subset, 0, 0);
    return 0;
}