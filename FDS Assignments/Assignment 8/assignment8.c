#include <stdio.h>

void bubblesort(int[],int);
void displayarr(int [],int);
void selectionsort(int[],int);
void insertionsort(int[],int);

int main ()
{
  int arr[20] , choice , size , i;

  printf("Enter the size of array :");
  scanf("%d",&size);

  printf("Enter Elements of array :\n");
  for (i=0 ; i<size ; i++)
  {
   scanf("%d",&arr[i]);
  }

  printf("Enter :\n");
  printf("1. To Use Bubble Sort\n");
  printf("2. To use Selection Sort\n");
  printf("3. To use Insertion Sort\n");
  printf("Your choice :");
  scanf("%d",&choice);


  switch(choice)
    {
        case 1: bubblesort(arr,size);
                break;

        case 2: selectionsort(arr,size);
                break;

        case 3: insertionsort(arr,size);
                break;

        default: printf("Invalid Inpur Please try again");
  }

 printf("\nAfter Sorting array is :\n ");
 displayarr(arr,size);

}


void displayarr(int arr[],int size)
{
 int i;

 for (i = 0 ; i<size ; i++)
 {
    printf("%d ",arr[i]);
 }
}

void bubblesort(int arr[],int size)
{
  int i,j ,temp;

 for ( i=0 ; i<size-1 ; i++)
   {
     for (j=0 ; j<size-1-i ; j++)
     {
         if (arr[j]>arr[j+1])
          {
            temp = arr[j];
            arr[j]=arr[j+1];
            arr[j+1]= temp;
          }
     }
   }
}


void selectionsort(int arr[],int size)
{
  int i,j ,temp;

 for ( i=0 ; i<size-1 ; i++)
   {
     for (j=i+1 ; j<size ; j++)
     {
         if (arr[i]>arr[j])
          {
            temp = arr[i];
            arr[i]=arr[j];
            arr[j]= temp;
          }
     }
   }
}

void insertionsort(int arr[] , int size)
{
  int element ,j, i,temp;

  i = 1;

  while (i<size)
  {
    element = arr[i];
    j = i-1;


    while (j >=0 && arr[j]>element)
    {
      arr[j+1] = arr[j];
      j=j-1;
    }

    arr[j+1] = element;
    i++;
  }
}
