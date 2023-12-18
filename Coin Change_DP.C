#include <stdio.h> 

int min(int a,int b) 
{ 
    if(a<b) return a; 
    else return b; 
} 

int main() 
{ 
    int deno[100];
    printf("Harsh Shetye_60009210068_Dynamic Programming_Coin Change Problem\n\n"); 
    printf("Enter the number of Denominations : "); 
    int n=0; 
    scanf("%d",&n); 
    int i=1; 
    while(i<n+1) 
    { 
        printf("enter the value of %dth denomination : ",i); 
        scanf("%d",&deno[i]); 
        i++; 
    } 
    int target=0; 
    printf("Enter the target sum : "); 
    scanf("%d",&target); 
    int dp[100][100]={0}; 
    for(int j=1;j<target+1;j++) 
    { 
        for(i=1;i<n+1;i++) 
        { 
            if((i==1 && i==j) || (i==1)) 
            { 
                dp[i][j]=1+dp[1][j-deno[i]]; 
            } 
            else if(j<deno[i]) 
            { 
                dp[i][j]=dp[i-1][j]; 
            } 
            else 
            { 
                dp[i][j]=min(dp[i-1][j],(1+dp[i][j-deno[i]])); 
            } 
        } 
    } 
    printf("\nThe least number of coins required is : %d \n\n",dp[n][target]); 
    int solution[100]={0}; 
    i=n; 
    int k=0; 
    int j=target; 
    while(j>0) 
    { 
        if(dp[i][j]==dp[i-1][j]) 
        { 
            i--; 
            continue; 
        } 
        else 
        { 
            target=target-deno[i]; 
            solution[k]=deno[i]; 
            k++; 
            j=target; 
            continue; 
        } 
    } 
    i=0; 
    while(i<k) 
    { 
        printf("The %dth coin in the solution set is : %d \n",i+1,solution[i]); 
        i++; 
    } 
    return 0; 
}