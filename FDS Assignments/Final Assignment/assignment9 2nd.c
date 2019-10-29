#include <stdio.h>
#include <stdlib.h>

void merge(int [] , int , int , int , int );

void merge_sort(int [] , int , int , int );


int main ()
{
    int size  , i ;

    printf("Enter size of array : ");
    scanf("%d",&size);

    int arr[size];
    int max = size ;

    printf("Enter Array Terms :");

    for (i=0 ; i<size ;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Current Array terms :  ");
    for (i=0 ; i<size ;i++)
    {
        printf("%d ",arr[i]);
    }

    merge_sort(arr , 0 , size-1 , max);

    printf("\nsorted Array terms : \n ");
    for (i=0 ; i<size ;i++)
    {
        printf("%d ",arr[i]);
    }

}

void merge(int arr[] , int low , int mid , int high , int max)
{
    int i , j , k;

    int temp[high- low + 1];

    i=low ; j = mid+1 ; k = 0 ;


    while ( i <= mid && j <=high)
    {
        if ( arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }

        else if ( arr[j] < arr[i])
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while ( i < mid+1)
    {
        temp[k] = arr[i];
        i++ ; k++;
    }

    while (j < high+1)
    {
        temp[k] = arr[j];
        j++ ; k++ ;
    }


    for ( i = 0 ; i < k ; i++)
    {
        arr[low] = temp[i];
        low++;
    }
    printf("\n");

    printf("pass: \n");

    for ( i = 0 ; i < max ; i++)
    {
        printf("%d ", arr[i]);
    }


}


void merge_sort(int arr[] , int low , int high , int max)
{
    int mid ;

    if (low < high)
    {
         mid = (low +high)/2;

        merge_sort(arr , low , mid , max);
        merge_sort(arr , mid+1,  high , max);

        merge(arr , low , mid , high , max);
    }
}
