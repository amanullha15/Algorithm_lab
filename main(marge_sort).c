#include<stdio.h>
#include<time.h>
#include <sys/time.h>
#include<stdlib.h>

#define SIZE 100000
#define SIZE1 10

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void marge_sort(int arr[], int l, int r)
{
    if(l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        marge_sort(arr, l, m);
        marge_sort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    struct timeval time_v,time_v1;
    struct timezone time_z,tz1;
    struct tm *tm;
    clock_t start,end;
    int i,n,a1[SIZE1],total;
    long int a[SIZE];
    FILE *fptr;


    for (i=0;i<SIZE1;i++)
    {
        a1[i]=rand()%1000+1;
    }
    gettimeofday(&time_v, &time_z);

    marge_sort(a1,0,SIZE1-1);

    tm=localtime(&time_v.tv_sec);
    printf(" 5 input  to do the sorting took %d m sec \n",tm->tm_sec);

    fptr = fopen("program1.txt","w");


    for (i=0;i<SIZE;i++)
    {
      fprintf(fptr,"%d, ",rand()%1000+1);
    }
    fflush(fptr);
    fclose(fptr);
    fptr = fopen("program1.txt","r");
    start = clock();


    for(i=0;i<SIZE;i++)
    {
       fscanf(fptr,"%d",&a[i]);
    }
    fclose(fptr);

    marge_sort(a,0,SIZE-1);

    end = clock();
    fptr=fopen("out.text","w");


    for (i=0;i<SIZE;i++)
    {
        fprintf(fptr,"%d, ",a[i]);
    }
    fclose(fptr);
    total = ((double)(end-start))*1000/CLOCKS_PER_SEC;
    printf("\n For 1M input time took %d m sec\n",total);


    int tt=total-tm->tm_sec;
    printf("\nTime difference: %d m sec\n",tt);

    return 0;
}
