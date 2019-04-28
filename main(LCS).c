#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int i,j,m,n,N[10][10];
char X[10],Y[10],S[10][10];


void PRINT(int m,int n)
{

    if(m==0 || n==0)
    {
        return;
    }

    if( S[m][n]=='C')
    {
        PRINT(m-1,n-1);
        printf("%c",X[m-1]);
    }

    else if (S[m][n]=='U')
    {
        PRINT(m-1,n);

    }

    else
    {
        PRINT(m,n-1);
    }

}


void LCS()
{
    m=strlen(X);
    n=strlen(Y);

    for(i=0; i<=m; i++)
    {
        N[i][0]=0;
    }

    for(i=0; i<=n; i++)
    {
        N[0][i]=0;
    }


    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
        {
            if (X[i-1]==Y[j-1])
            {
                N[i][j]=N[i-1][j-1]+1;
                S[i][j]='C';
            }

            else  if (N[i-1][j]>=N[i][j-1])
            {
                N[i][j]=N[i-1][j];
                S[i][j]='U';
            }

            else
            {
                N[i][j]=N[i][j-1];
                S[i][j]='L';
            }
        }
    }
}


int main()
{
    printf("Enter value of  X : ");
    scanf("%s",X);

    printf("\nEnter value of  Y : ");
    scanf("%s",Y);

    printf("\n LONGEST Subsequence are : ");
    LCS();
    PRINT(m,n);

    printf("\n Length is :  %d",N[m][n]);

    return 0;
}
