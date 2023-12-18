#include<stdio.h>

int main()
{
    int i,j;
    int min[100],max[100];
    int ignore,sum=0;
    int mini,minj;
    int vali[100];
    int valj[100];
    int v;
    int a[100][100];
    printf("\nHarsh Shetye_60009210068\nKruskal's Algorithm\n");
    printf("Enter the number of vertices\n");
    scanf("%d",&v);
    for(i=0; i<v; i++) {
        for(j=0; j<v; j++) {
            printf("Enter value of Ajacency Matrix:\n");
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0; i<v; i++) {
        mini=0;
        minj=0;
        min[i]=100;
        max[i]=a[i][0];
        for(j=0; j<v; j++) {
            if(a[i][j]<=min[i] && a[i][j]!=0) {
                min[i]=a[i][j];
                mini=i;
                minj=j;
            }
            if(a[i][j]>max[i]) {
                max[i]=a[i][j];
            }
        }
        vali[i]=mini;
        valj[i]=minj;
    }
    for(i=0; i<v-1; i++) {
        if(vali[i]==valj[i+1] && vali[i+1]==valj[i]) {
            ignore=i;
        }
    }
    printf("\nFollowing are the minimum edge weights:\n");
    for(i=0; i<v; i++) {
        if(i!=ignore) {
            printf("{%d , %d} = %d\n", vali[i]+1, valj[i]+1, min[i]);
            sum=sum+min[i];
        }
    }
    printf("\nThe cost of MST is:%d\n",sum);
    return 0;
}