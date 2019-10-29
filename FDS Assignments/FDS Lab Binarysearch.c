#include <stdio.h>

void sort();
void input(int [], int size);
void sort (int *, int);
int binarysearch(int [], int , int ,int );

main()
{
  int size,i,element,low,mid , result ;

  printf ("Enter the size of array\n");
  scanf("%d",&size);

  int arr[size];

  input(arr,size);

  sort(arr,size);

   printf("Sorted array is  :  ");

   for (i=0;i<size;i++)
   {
       printf ("%d  ",arr[i]) ;
   }

   printf ("\n\nEnter the element to search\n");
   scanf("%d",&element);

   result = binarysearch(arr, 0 , size , element);

   if (result != -1)
   {
     printf("\nEntered element %d is found in the array ar position %d",arr[result],result+1);
   }

   else
   {
     printf("\nEntered element is not found in array");

   }

}

void input(int arr[], int size)
{
   int i ;

   printf("Enter the elements of array \n ");

   for (i=0;i<size;i++)
   {
       scanf ("%d",&arr[i]) ;
   }

}

void sort (int arr[] , int size)
{
  int temp , i , j;

   for (i=0;i<size-1;i++)
   {
           for (j=i+1;j<size;j++)
           {
              if (arr[i] > arr[j])
              {
                 temp = arr[i];
                 arr[i]= arr[j];
                 arr[j]= temp;
              }
            }
   }
}

int binarysearch(int arr[], int low ,int high ,int element)
{
    if (high >= low)
    {

      int mid = (high+low)/2;
      if (arr[mid]== element) return mid ;

      else if (element >arr[mid]) return binarysearch (arr,mid+1,high,element);
      else if (element < arr[mid]) return binarysearch(arr,low,mid-1,element);

      else return -1;
    }
}

