#include <stdio.h>
#include <math.h>

struct poly{
    float coeff;
    int expo;
}p1[10],p2[10];

int term1,term2,term3;

void inputpoly(struct poly p[], int );
void displaypoly (struct poly p[],int );
void sortpoly ( struct poly p[] , int );
void substitution ( struct poly p[] , int , int );
void addition (struct poly p1[],struct poly p2[],int term1, int term2);
void subtraction (struct poly p1[],struct poly p2[],int term1, int term2);
void multiplication (struct poly p1[],struct poly p2[],int term1, int term2);

int main ()
{
   int i,j,x;
   int choice;
   char exit;

do{
   exit='n';
   printf("\nEnter:\n");
   printf("1. To Input Polynomials\n");
   printf("2. To Display Entered Polynomials\n");
   printf("3. To Substitute value in Polynomials and Get Answer\n");
   printf("4. To Add entered Polynomials\n");
   printf("5. To Subtracy entered Polynomials\n");
   printf("6. To Multiply entered Polynomials\n");
   printf("7. To exit\n");
   printf("Your choice :");
   scanf("%d",&choice);
   switch (choice)
   {

        case 1:  printf("Enter no of terms in Poly 1 : ");
                 scanf("%d",&term1);
                 printf("Enter Polynomial 1\n");
                 inputpoly(p1,term1);

                 printf("Enter no of terms in Poly 1 : ");
                 scanf("%d",&term2);

                 printf("Enter Polynomial 2\n");
                 inputpoly(p2,term2);
                 break;

        case 2:
                printf("Entered poly are :\n");
                displaypoly (p1,term1) ;
                displaypoly (p2,term2) ;
                break;

        case 3:
                printf("Enter value of X");
                scanf("%d",&x);

                printf("After Substituting x=%d in poly 1\n",x);
                substitution ( p1 , term1, x);

                printf("After Substituting x=%d in poly 2\n",x);
                substitution ( p2 , term2, x);
                break;

        case 4:  printf("After Addition of both Polynomials :  \n") ;
                 addition (p1,p2,term1,term2);
                 break;

        case 5:  printf("After Subtraction of both Polynomials :  \n") ;
                 subtraction(p1,p2,term1,term2);
                 break;

        case 6:  printf("After Multiplication of both Polynomials :  \n") ;

                 multiplication(p1,p2,term1,term2);
                 break;

        case 7 : exit = 'y';
                 break;

        default: printf("invalid Input");

    }
}while (exit=='n');
}


void inputpoly(struct poly p[],int term)
{

  int i;

  printf("\n");

  for (i=0;i<term;i++)
  {
   printf("Enter Coeffecient of Term %d : ",i+1);
   scanf("%f",&p[i].coeff);
   printf("Enter Exponent power of Term %d : ",i+1);
   scanf("%d",&p[i].expo);
  }

  sortpoly(p,term);
  printf("\n");
}


void displaypoly (struct poly p[],int term)
{
  int i;
  for (i=0;i<term;i++)
  {
   printf("%.2fX^%d",p[i].coeff,p[i].expo);
   if (i!=term-1) printf(" + ");
  }
  printf("\n");
}

void sortpoly(struct poly p[],int term)
{
  int i,j;
  struct poly temp;
  for (i=0;i<term-1;i++)
  {
    for (j=0;j<term-i-1;j++)
    {
      if (p[j].expo<p[j+1].expo)
      {
        temp=p[j];
        p[j]=p[j+1];
        p[j+1]=temp;
      }
    }
  }
}

void substitution ( struct poly p[] , int term, int x)
{
  int i;
  float result=0 ;
  for (i=0;i<term;i++)
  {
   result = result + p[i].coeff*(pow(x,p[i].expo));
  }

  printf("Answer : %.2f\n\n",result);
 }



void addition (struct poly p1[],struct poly p2[],int term1, int term2)
{
  int i=0,j=0;
  int totalterms = 0;

  struct poly addition[term1+term2];

  while (i<term1 && j < term2)
  {
     if (p1[i].expo>p2[j].expo)
          {
            addition[totalterms]=p1[i];
            i++;
            totalterms++;                               // Both of these loop will add the greater term from both directly
          }                                             // to addition poly

      else if (p1[i].expo<p2[j].expo)
          {
            addition[totalterms] = p2[j];
            j++;
            totalterms++;
          }

      else if (p1[i].expo == p2[j].expo)
          {                                                         // In case power of term match this will add the coeff
            addition[totalterms].expo = p1[i].expo;                  // and put the term into addition poly
            addition[totalterms].coeff = p1[i].coeff + p2[j].coeff;
            i++;j++;totalterms++;
          }
  }

  while ( i < term1 )
  {
    addition[totalterms] = p1[i];                 // In this remaining terms from poly 1 is directly copied to addition poly
    totalterms++;
    i++;
  }

  while ( j < term2 )
  {
    addition[totalterms] = p2[j];              // In this remaining terms from poly 2 is directly copied to addition poly
    totalterms++;
    j++;
  }

  displaypoly(addition,totalterms);
}

void subtraction (struct poly p1[],struct poly p2[],int term1, int term2)
{
  int i=0,j=0;
  int totalterms = 0;

  struct poly subtract[term1+term2];

  while (i<term1 && j < term2)
  {
     if (p1[i].expo>p2[j].expo)
          {
            subtract[totalterms]=p1[i];
            i++;
            totalterms++;
          }                                   // Both of these loop will add the greater term from both directly
                                              // to subtract poly
      else if (p1[i].expo<p2[j].expo)
          {
            subtract[totalterms] = p2[j];
            j++;
            totalterms++;
          }


      else if (p1[i].expo == p2[j].expo)                        // In case power of term match this will subtract the coeff
          {                                                      // and put the term into subtract poly
            subtract[totalterms].expo = p1[i].expo;
            subtract[totalterms].coeff = p1[i].coeff - p2[j].coeff;
            i++;
            j++;
            totalterms++;
          }
  }

  while ( i < term1 )
  {
    subtract[totalterms] = p1[i];      // In this remaining terms from poly 1 is directly copied to subtraction poly
    totalterms++;
    i++;
  }

  while ( j < term2 )
  {
    subtract[totalterms] = p2[j];     // In this remaining terms from poly 2 is directly copied to subtraction poly
    totalterms++;
    j++;
  }

  displaypoly(subtract,totalterms);
}


void multiplication (struct poly p1[],struct poly p2[],int term1, int term2)
{
   int i = 0, j, totalterms = 0 , k = 0 ;

   struct poly multi[term1*term2];


    while ( i < term1)

    {                                                           // Multiplying One element poly 1 to all elements of poly 2
         j=0;                                                   // using Double loops
                                                                // And Store them in multiply polynomial
         while (j< term2)
        {
         multi[totalterms].coeff  = p1[i].coeff * p2[j].coeff;
         multi[totalterms].expo   = p1[i].expo + p2[j].expo;
         totalterms++;
         j++;
        }
        i++;
    }

    sortpoly(multi ,totalterms);

    for ( i = 0; i < totalterms - 1 ; i++)                          // This Function will add coeff of terms with
    {                                                               // Same exponential power and remove extra terms
       if ( multi[i+1].expo == multi[i].expo)
           {
              multi[i].coeff = multi[i+1].coeff + multi[i].coeff;

              k=i+1;
              while ( k < totalterms)
                  {
                     multi[k] = multi[k+1];                 // adter adding coeff . the second term with same power is
                     k++;                                   // removed by moving x+1 position term to x position
                  }

              totalterms--;
              i--;
           }
    }

displaypoly(multi , totalterms);

}
