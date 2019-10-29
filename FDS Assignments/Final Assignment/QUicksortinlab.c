#include <stdio.h>
#include<stdlib.h>

// Quick Sort using Middle Element as Pivot

void swap(int *a , int*b)
{
    int temp ;
    temp = *a ;
    *a = *b ;
    *b = temp;
}

int partition (int arr[] , int low , int high)
{
    int mid = (low+high)/2;

    swap(&arr[low] , &arr[mid]);

    int pivot = arr[low] ;
    int i , j , k ;

        i = low+1 ;
        j= high;

    while(i <= j)
    {

        while (arr[i]<=pivot && i<=high)
        {
            i++;
        }

        while (arr[j]>pivot && j>=low)
        {
            j--;
        }
       if (i<j) swap(&arr[i],&arr[j]);
    }

    swap(&arr[low]   ,   &arr[j]);
    return j;
}

void quicksort(int arr[] , int low , int high)
{
    if (low <= high)
    {
        int pi = partition (arr , low , high);

        quicksort(arr , low , pi-1);
        quicksort(arr , pi+1 , high);
    }
}

int main()
{
    int size ;
    int *arr;
    int i;
    printf("Enter size : ");
    scanf("%d" , &size);

    arr = malloc(size * sizeof(int));

    printf("Enter array terms :  ");
    for(i=0 ; i<size ; i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("\nArray terms Are :\n");
    for(i=0 ; i<size ; i++)
    {
        printf("%d ",arr[i]);
    }

    quicksort(arr,0,size-1);
    printf("\nAfter Sorting:\n");

    for (i=0 ; i<size ; i++)
    {
        printf("%d ",arr[i]);
    }
}
