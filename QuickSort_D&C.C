#include<stdio.h>
int swap(int *a,int *b){
    int temp = *a;
    *a=*b;
    *b= temp;
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n= sizeof(arr)/sizeof(arr[0]);
    int pivot = arr[n-1];
    int i=-1;
    for(int j=0;j<n-1;j++){
        if(arr[j]<=pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[n-1]);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

}