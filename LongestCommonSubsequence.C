#include<stdio.h>
#include<string.h>

int i,j,m,n,c[50][50];
char x[50],y[50],b[50][50];

void print_lcs(int i,int j)
{
    if(i==0 || j==0)
        return;
    if(b[i][j]=='c') {
        print_lcs(i-1,j-1);
        printf("%c",x[i-1]);
    } else if(b[i][j]=='u')
        print_lcs(i-1,j);
    else
        print_lcs(i,j-1);
}

void lcs()
{
    m=strlen(x);
    n=strlen(y);
    for(i=0; i<=m; i++)
        c[i][0]=0;
    for(i=0; i<=n; i++)
        c[0][i]=0;

    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++) {
            if(x[i-1]==y[j-1]) {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='c';
            } else if(c[i-1][j]>=c[i][j-1]) {
                c[i][j]=c[i-1][j];
                b[i][j]='u';
            } else {
                c[i][j]=c[i][j-1];
                b[i][j]='l';
            }
        }
}

int main()
{   printf("\nHarsh Shetye_60009210068_LCS_DAOA\n");
    printf("\nEnter 1st sequence : ");
    scanf("%s",x);
    printf("Enter 2nd sequence : ");
    scanf("%s",y);
    printf("\nThe Longest Common Subsequence is ");
    lcs();
    print_lcs(m,n);
    return 0;
}


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int max(int a, int b) {
//     return (a > b) ? a : b;
// }

// char* lcs(char* x, char* y) {
//     int m = strlen(x);
//     int n = strlen(y);
//     int** c = (int**)malloc(sizeof(int*) * (m + 1));
//     for (int i = 0; i <= m; i++) {
//         c[i] = (int*)malloc(sizeof(int) * (n + 1));
//         memset(c[i], 0, sizeof(int) * (n + 1));
//     }

//     for (int i = 1; i <= m; i++) {
//         for (int j = 1; j <= n; j++) {
//             if (x[i - 1] == y[j - 1]) {
//                 c[i][j] = c[i - 1][j - 1] + 1;
//             } else {
//                 c[i][j] = max(c[i - 1][j], c[i][j - 1]);
//             }
//         }
//     }

//     int len = c[m][n];
//     char* result = (char*)malloc(sizeof(char) * (len + 1));
//     result[len] = '\0';
//     int i = m, j = n;
//     while (i > 0 && j > 0) {
//         if (x[i - 1] == y[j - 1]) {
//             result[len - 1] = x[i - 1];
//             i--;
//             j--;
//             len--;
//         } else if (c[i - 1][j] > c[i][j - 1]) {
//             i--;
//         } else {
//             j--;
//         }
//     }

//     for (int i = 0; i <= m; i++) {
//         free(c[i]);
//     }
//     free(c);
//     return result;
// }

// int main() {
//     printf("\nHarsh Shetye_60009210068_LCS_DAOA\n");
//     char x[50], y[50];
//     printf("\nEnter 1st sequence : ");
//     scanf("%s", x);
//     printf("Enter 2nd sequence : ");
//     scanf("%s", y);
//     char* result = lcs(x, y);
//     printf("\nThe Longest Common Subsequence is %s", result);
//     free(result);
//     return 0;
// }
