#include<stdio.h>
int max, min;
void dc_maxmin(int H[], int i, int j)
{
    int max1, min1, mid;
    if(i==j) {
        max = min = H[i];
    } else {
        if(i == j-1) {
            if(H[i] <H[j]) {
                max = H[j];
                min = H[i];
            } else {
                max = H[i];
                min = H[j];
            }
        } else {
            mid = (i+j)/2;
            dc_maxmin(H , i, mid);
            max1 = max;
            min1 = min;
            dc_maxmin(H, mid+1, j);
            if(max <max1)
                max = max1;
            if(min > min1)
                min = min1;
        }
    }
}
int main ()
{
    int i, num, H[100];
    printf("\nHarsh Vikas Shetye 60009210068\n\nExperiment 1 Min Max Algorithm\n");
    printf("\nEnter the total number of numbers : ");
    scanf("%d",&num);
    printf("Enter the numbers : \n");
    for(i=1; i<=num; i++)
        scanf ("%d",&H[i]);

    max = H[0];
    min = H[0];
    dc_maxmin(H, 1, num);
    printf("Minimum value : %d\n", min);
    printf("Maximum value : %d\n", max);
    return 0;
}
