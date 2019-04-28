#include<stdio.h>
#include<stdlib.h>

int  main()
{
    int i,n;
    printf("Enter num:");
    scanf("%d",&n);
    int s[n],f[n];
    printf("Enter s :");
    for(i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
    }

 printf("Enter f :");
    for(i=0;i<n;i++)
    {
        scanf("%d",&f[i]);
    }

    for(i=0; i<n; i++)
    {
        int j=0;
        printf("%d ",j);
        if(s[i+1]>f[i])
        {
            printf("%d ",s[i+1]);

        }
    }
return 0;
}

