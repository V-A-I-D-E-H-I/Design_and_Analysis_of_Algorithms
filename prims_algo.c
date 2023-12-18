#include<stdio.h>
#include<limits.h>
#define i 30000
int main()
{
    int cost[8][8]={{i,i,i,i,i,i,i,i},
                    {i,i,25,i,i,i,15,i},
                    {i,25,i,12,i,i,i,10},
                    {i,i,12,i,8,i,i,i},
                    {i,i,i,8,i,16,i,14},
                    {i,i,i,i,16,i,20,18},
                    {i,5,i,i,i,20,i,i},
                    {i,i,10,i,14,18,i,i}};
    int near[8] = {i,i,i,i,i,i,i,i};
    int tree[2][6];
    int min,u,v;
    int n=7;
    min=INT_MAX;
    
    for(int j=1;j<=n;j++)
    {
        for(int k=1;k<=n;k++)
        {
            if(cost[j][k] < min)
            {
                min=cost[j][k];
                u=j;
                v=k;
                
            }
            else {
                continue;
                }
        }
    }

    tree[0][0]=u;
    tree[1][0]=v;
    near[u]=near[v]=0;
    //finding which is the next connected nearest vertex.
    for(int j=1;j<=n;j++)
    {
        if((near[j]!=0) && (cost[j][u] < cost[j][v]) )
        {
            near[j]=u;
        }
        else if( (near[j]!=0) && cost[j][u] >= cost[j][v]) { 
            near[j]=v;
        }
    }    
int counter_tree=1;
int k;
for(counter_tree=1;counter_tree<n-1;counter_tree++)
{   min=i;
   for(int j=1;j<=n;j++)
    {
        if( near[j]!=0 && cost[j][near[j]]<min)
        {
            min=cost[j][near[j]];
            k=j;
        }
        else continue;
    }
    tree[0][counter_tree]=k;   
    tree[1][counter_tree]=near[k];
    near[k]=0;
    for(int j=1;j<=n;j++)
    {
        if((near[j]!=0) && (cost[j][k] < cost[j][near[j]]))
        {
            near[j]=k;
        }
        else 
        {
            continue;
        }
    }
}
printf("The MST is : \n");
for(int x=0;x<2;x++)
{
    for(int y=0;y<6;y++)
    {
        printf("%d ",tree[x][y]);
    }
    printf("\n");
}
return 0;
}
//correct hai. (checked)!!!
