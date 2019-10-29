#include <stdio.h>

int search_linear(int [],int , int );
void search_linearMO(int [],int , int );
int search_binary(int [],int ,int , int );
int search_binaryrecur(int [],int ,int , int );
void array_sort(int [], int );

int main()
{
   int arr[20],size,i;
   int num,pos,choice;       // pos is position , size is size of array

   printf("Enter Size of array : ");
   scanf("%d",&size);

   printf("Enter Elements of array:\n");
   for (i=0;i<size;i++)
   {
    scanf("%d",&arr[i]);
   }

   printf("Enter Number To search : ");
   scanf("%d",&num);

   printf("Enter:\n");
   printf("1. To  use Linear Search\n");
   printf("2. To  use Linear Search by recursion\n");
   printf("3. To  use Binary Search\n");
   printf("4. To  use Binary Search recursive method\n");
   printf("Your Choice :");
   scanf("%d",&choice);

   switch (choice)
   {
    case 1 : pos = search_linear(arr,size,num);
             if (pos!= -1)
            {
              printf("Number %d is present as Position %d in Array",num,pos+1);
            }

            else printf("Number Not present in array\n");
            break;

    case 2: search_linearMO(arr,size,num);
            break;

    case 3: pos = search_binary(arr , size , size-1 , num);
            if (pos!= -1)
            {
              printf(" After Sorting array and search using binary search \nNumber %d is present as Position %d in Array",num,pos+1);
            }

            else printf("Number Not present in array\n");
            break;

    case 4:
            array_sort(arr,size);
            pos = search_binaryrecur(arr , 0 , size-1, num);
            if (pos!= -1)
            {
              printf("after Array is sorted \n");
              printf("Number %d is present in Array at position %d",num,pos+1);
            }

            else printf("Number Not present in array\n");
            break;

    default : printf("Invalid input\n");
   }

}

void array_sort(int arr[], int size)
{
  int i , j , temp;

  for ( i = 0 ; i< size-1 ; i++)              // Sorting array using Bubble sort for binary search
  {
    for ( j = 0 ; j < size-1-i ; j++)
    {
      if ( arr[j]>arr[j+1])
      {
       temp = arr[j];
       arr[j] = arr[j+1];
       arr[j+1] = temp;
      }
    }
  }
}


int search_linear(int arr[],int size, int num)
{
  int i ;

  for (i = 0 ; i < size ; i++)
  {
   if (arr[i]==num)
   {
        return i;
   }
  }
}


void search_linearMO(int arr[],int size, int num)
{
  int i ,count = 0;

  for (i = 0 ; i < size ; i++)
  {
   if (arr[i]==num)
   {
        count++;
        printf("Number : %d is present at position :%d \n",num,i+1);
   }
  }

  if (count !=0) printf("\nNumber : %d is present %d times in array",num,count);
  else printf("Entered Number not present in array");

}

int search_binary(int arr[], int size ,int high , int num)
{
  int mid, i ,low = 0;

  while (low <= high)
  {
   mid = (low+high)/2;

   if (arr[mid]==num) return mid ;
   else if (arr[mid]<num) low = mid+1;
   else if (arr[mid]>num) high = mid-1;
  }
}

int search_binaryrecur( int arr[], int low ,int high , int num)
{
  int mid;

  while (low <= high)
  {
   mid = (low+high)/2;

   if (arr[mid]==num) return mid ;
   else if (arr[mid]<num) return search_binaryrecur(arr,mid+1,high,num);
   else if (arr[mid]>num) return search_binaryrecur(arr,low,mid-1,num);
  }
  return -1;
}
