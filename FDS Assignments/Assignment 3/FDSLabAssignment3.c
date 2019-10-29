#include <stdio.h>

int matrixinput(int rows,int columns,int matrix[rows][columns]);
void printmatrix(int rows,int columns,int matrix[rows][columns]);
void matrixaddition();
void matrixsubtraction();
void matrixtranspose();
void matrixmultiplication();
void maxmnoofeachrowmatrix();
void addnofmajordiagonalelements();
void addnofminordiagonalelements();
void lowertriangularmatrix();
void uppertriangularmatrix();
void symmetricmatrixcheck();
void arrayelementdeletion();
void arrayelementinsertion();

main()
{
	int choice;

    menu:
	printf ("Enter which operation to perform\n");
	printf("Enter 1. For Additon of 2 Matrix\n");
	printf("Enter 2. For Subtraction of 2 Matrix\n");
	printf("Enter 3. For Transpose of a Matrix\n");
	printf("Enter 4. For Multiplication of 2 Matrix\n");
	printf("Enter 5. To Find Maximum element in each Row of a Matrix\n");
	printf("Enter 6. To Add Major Diagonal Elements of 2 Matrices\n");
	printf("Enter 7. To Add Minor Diagonal Elements of 2 Matrices\n");
	printf("Enter 8. To Print Lower Triangular matrix form of Entered matrix\n");
	printf("Enter 9. To Print Upper Triangular matrix form of Entered matrix\n");
	printf("Enter 10. To Check if Entered Matrix is Symmetric or not\n");
	printf("Enter 11. To Delete an Element of an Array\n");
	printf("Enter 12. To Insert an element into an Array\n");
	printf("Your Input : ");
	scanf("%d",&choice);
    switch(choice)
	{
		case 1:matrixaddition();
		       break;

		case 2:matrixsubtraction();
		       break;

		case 3:matrixtranspose();
		       break;

		case 4:matrixmultiplication();
		       break;

        case 5:maxmnoofeachrowmatrix();
               break;

        case 6:addnofmajordiagonalelements();
               break;

        case 7:addnofminordiagonalelements();
               break;

		case 8:lowertriangularmatrix();
               break;

        case 9:uppertriangularmatrix();
               break;

        case 10:symmetricmatrixcheck();
                break;

        case 11:arrayelementdeletion();
                break;

        case 12:arrayelementinsertion();
                break;


        default: printf("invalid Input\n");
                 printf("Please Try again \n");
                 goto menu;
	}
}

int matrixinput(int rows,int columns,int matrix[][columns])
{
  int row,column;

	for (row=0;row<rows;row++)
	{
		for (column=0;column<columns;column++)
		{
			scanf("%d",&matrix[row][column]);
		}
	}
}

void printmatrix(int rows,int columns,int matrix[][columns])
{
   int row,column;

   for (row=0;row<rows;row++)
	{
		for (column=0;column<columns;column++)
		{
			printf("%d ",matrix[row][column]);
		}
		printf("\n");
	}
    printf("\n\n");
}

void matrixaddition()
{
    int rows,columns,row,column;

	printf("Enter the dimension of matrix\n");
	printf("Enter the number of Rows : ");
	scanf("%d",&rows);

	printf("Enter the number of columns : ");
	scanf("%d",&columns);

	int matrix1[rows][columns],matrix2[rows][columns];

	printf ("Enter The elements of Matrix 1\n");

	matrixinput(rows,columns,matrix1);

    printf ("Enter The elements of Matrix2\n");

	matrixinput(rows,columns,matrix2);

    for (row=0;row<rows;row++)
    {
        for (column=0;column<columns;column++)
        {
          matrix1[row][column]+=matrix2[row][column];
        }
    }
	printf ("result of Addition of both matrix is \n");
    printmatrix(rows,columns,matrix1);
}


void matrixsubtraction()
{
	int rows,columns,row,column;

	printf("Enter the dimension of matrix\n");
	printf("Enter the number of Rows : ");
	scanf("%d",&rows);
	printf("Enter the number of columns : ");
	scanf("%d",&columns);

	int matrix1[rows][columns],matrix2[rows][columns];
	printf ("Enter The elements of Matrix 1\n");
	matrixinput(rows,columns,matrix1);

    printf ("Enter The elements of Matrix2\n");
	matrixinput(rows,columns,matrix2);

		for (row=0;row<rows;row++)
        {
            for (column=0;column<columns;column++)
            {
                matrix1[row][column]-=matrix2[row][column];
            }
        }
	printf ("result of Subtraction of both matrix is \n");
    printmatrix(rows,columns,matrix1);
}

void matrixtranspose()
{
	int rows,columns,row,column;
	printf("Enter the dimension of matrix\n");
	printf("Enter the number of Rows : ");
	scanf("%d",&rows);
	printf("Enter the number of columns : ");
	scanf("%d",&columns);

	int matrix[rows][columns],transpose[columns][rows];

    printf ("Enter elements of matrix\n");
	matrixinput(rows,columns,matrix);

	for (row=0;row<rows;row++)
	{
		for (column=0;column<columns;column++)
		{
			transpose[column][row]=matrix[row][column];
		}
	}
	printf ("Transpose of Entered matrix is \n");
    printmatrix(columns,rows,transpose);
}

void matrixmultiplication()
{
	int rows1,columns1,rows2,columns2,row,column,element;
    input:
	printf("Enter the number of Rows in matrix 1: ");
	scanf("%d",&rows1);
	printf("Enter the number of columns in matrix 1: ");
	scanf("%d",&columns1);

	printf("Enter the number of Rows in matrix 2: ");
	scanf("%d",&rows2);
	printf("Enter the number of columns in matrix 2: ");
	scanf("%d",&columns2);

	if (rows1!=columns2)
	{ printf("Invalid Input \n");
      printf("For Matrix Multiplicaion \nno of Rows of 1st matrix");
      printf("and no of Columns of 2nd matrix must be equal");
      printf("go to menu and try again");
      goto input;
	}

	int matrix1[rows1][columns1],matrix2[rows2][columns2],resultmatrix[rows1][columns2];

	printf ("Enter The elements of Matrix 1\n");
	matrixinput(rows1,columns1,matrix1);

    printf ("Enter The elements of Matrix2\n");
	matrixinput(rows2,columns2,matrix2);

	for (row=0;row<rows1;row++)
	{
	   for (column=0;column<columns2;column++)
	   {
	      resultmatrix[row][column]=0;
	   }
	}

	for (row=0;row<rows1;row++)
	{
	   for (column=0;column<columns2;column++)
	   {
	      for (element=0;element<columns1;element++)
	      {
	         resultmatrix[row][column]+= matrix1[row][element] * matrix2[element][column];
	      }
	      printf("%d ",resultmatrix[row][column]);
	   }
	   printf("\n");
	}
	printf ("The Resultant Matrix is \n");
	printmatrix(rows1,columns2,resultmatrix);
}

void maxmnoofeachrowmatrix()
{
    int rows,columns,row,column,maxm;

	printf("Enter the dimension of matrix\n");
	printf("Enter the number of Rows : ");
	scanf("%d",&rows);
	printf("Enter the number of columns : ");
	scanf("%d",&columns);

	int matrix[rows][columns];
	printf ("Enter The elements of Matrix 1\n");
	matrixinput(rows,columns,matrix);

	printf("Entered Matrix is \n");
	printmatrix(rows,columns,matrix);

	for (row=0;row<rows;row++)
	{
	  maxm=matrix[row][0];
	  for (column=0;column<columns;column++)
	  {
	    if (matrix[row][column]>=maxm) maxm=matrix[row][column];
	  }
	  printf("Maximimum Element of Row:%d is = %d\n",row+1,maxm);
	}
}

void addnofmajordiagonalelements()
{
	int rows,columns,row;

	printf("Enter the dimension of matrix\n");
	printf("Enter the number of Rows : ");
	scanf("%d",&rows);

	printf("Enter the number of columns : ");
	scanf("%d",&columns);

	int matrix1[rows][columns],matrix2[rows][columns];

	printf ("Enter The elements of Matrix 1\n");

	matrixinput(rows,columns,matrix1);

    printf ("Enter The elements of Matrix2\n");

	matrixinput(rows,columns,matrix2);

	for (row=0;row<rows;row++)
	{
		matrix1[row][row]+=matrix2[row][row];
	}
	printf ("Resultant matrix is \n");
	printmatrix(rows,columns,matrix1);
}

void addnofminordiagonalelements()
{
	int rows,columns,row,column;

	printf("Enter the dimension of matrix\n");
	printf("Enter the number of Rows : ");
	scanf("%d",&rows);

	printf("Enter the number of columns : ");
	scanf("%d",&columns);

	int matrix1[rows][columns],matrix2[rows][columns];

	printf ("Enter The elements of Matrix 1\n");

	matrixinput(rows,columns,matrix1);

    printf ("Enter The elements of Matrix2\n");

	matrixinput(rows,columns,matrix2);

	for (row=0,column=columns-1;row<rows;row++,column--)
	{
		matrix1[row][column]+=matrix2[row][column];
	}
	printf ("Resultant matrix is \n");
	printmatrix(rows,columns,matrix1);
}

void lowertriangularmatrix()
{
	int rows,columns,row,column;
	printf("Enter the dimension of matrix\n");
	printf("Enter the number of Rows : ");
	scanf("%d",&rows);

	printf("Enter the number of columns : ");
	scanf("%d",&columns);

	int matrix[rows][columns];

	printf ("Enter The elements of Matrix \n");

	matrixinput(rows,columns,matrix);

	for (row=0;row<rows;row++)
	{
		for (column=0;column<columns;column++)
		{
			if ( row<column) matrix[row][column]=0;
		}
	}
	printf ("Resultant Lower Triangular matrix of Entered matrix is \n\n");
	printmatrix(rows,columns,matrix);
}

void uppertriangularmatrix()
{
	int rows,columns,row,column;

	printf("Enter the dimension of matrix\n");
	printf("Enter the number of Rows : ");
	scanf("%d",&rows);

	printf("Enter the number of columns : ");
	scanf("%d",&columns);

	int matrix[rows][columns];

	printf ("Enter The elements of Matrix \n");

	matrixinput(rows,columns,matrix);

	for (row=0;row<rows;row++)
	{
		for (column=0;column<columns;column++)
		{
			if ( row>column) matrix[row][column]=0;
		}
	}
	printf ("Resultant Lower Triangular matrix of Entered matrix is \n\n");
	printmatrix(rows,columns,matrix);
}

void symmetricmatrixcheck()
{
    int rows,columns,row,column,flag=1;

	printf("Enter the dimension of matrix\n");
	printf("Enter the number of Rows : ");
	scanf("%d",&rows);
	printf("Enter the number of columns : ");
	scanf("%d",&columns);

	int matrix[rows][columns];

    printf ("Enter elements of matrix\n");
	matrixinput(rows,columns,matrix);

	printf("Entered matrix is \n");
	printmatrix(rows,columns,matrix);

	for (row=0;row<rows;row++)
	{
		for (column=0;column<columns;column++)
		{
			if ( matrix[row][column]!=matrix[column][row]) flag=0;
		}
	}
	if(flag==0) printf ("Entered Matrix is not symmetric matrix");
	else printf("Entered Matrix is A symmetric matrix\n");
}

void arrayelementdeletion()
{
	int size,element,i,count;
	printf ("Enter Size of Array\n");
    scanf ("%d",&size);

    int arr[size];
    printf("Enter Elements of array\n");
    for (i=0;i<size;i++)
    {
    	scanf("%d",&arr[i]);
    }

    printf ("Enter the element in array which to delete\n");
    scanf("%d",&element);
    for (i=0;i<size;i++)
    {
    	if (arr[i]==element)
    	{
    		for (count=i;count<size;count++)
    		{
    			arr[count]=arr[count+1];
    		}
    		size--;
    	}
    }
    printf("Final array after modification is \n");
     for (i=0;i<size;i++)
    {
       printf("%d ",arr[i]);
    }
}

void arrayelementinsertion()
{
	int size,element,i,position;
	printf ("Enter Size of Array\n");
    scanf ("%d",&size);

    int arr[size+1];
    printf("Enter Elements of array\n");
    for (i=0;i<size;i++)
    {
    	scanf("%d",&arr[i]);
    }

    printf ("Enter the element which to insert in array \n");
    scanf("%d",&element);
    printf ("Enter the position at which to insert element\n");
    scanf("%d",&position);
    position--;
    for (i=size;i>=position;i--)
    {
    	arr[i+1]=arr[i];
    }

    arr[position]=element;
    printf ("The array after modification is \n");
    for (i=0;i<size+1;i++)
    {
    	printf ("%d ",arr[i]);
    }
}
