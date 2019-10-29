#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std ;

/*
Question 3rd
int main()
{

    int num ;

    int *ptr = &num ;

    cout << &num <<" " << *(&num) << endl ;
    cout << &ptr <<" " << *ptr << " "<< ptr << endl ;

}
*/
/*
QUestion 4
int main()
{
    int num1 , num2 ;

    cout <<"Enter two numbers : ";
    cin >>num1 >> num2 ;

    int *ptr1 , *ptr2 ;

    ptr1 = &num1 ;
    ptr2 = &num2 ;

    int result = *ptr1 + *ptr2 ;

    cout << "Result is :" << result <<endl ;
    return 0;
}
*/

/*
Question 5
int sum(int *fno , int *sno)
{
    return (*fno + *sno);
}
int main()
{
    int num1 , num2 ;

    cout <<"Enter two numbers : ";
    cin >>num1 >> num2 ;

    int result = sum(&num1 , &num2);


    cout << "Result is :" << result <<endl ;
    return 0;
}
*/

/*
Question 6
int isMax(int *fno , int *sno)
{
    if (*fno >= *sno ) return *fno ;
    else return *sno;
}

int main()
{
    int num1 , num2 ;

    cout <<"Enter two numbers : ";
    cin >> num1 >> num2 ;

    int max = isMax(&num1 , &num2);

    cout << "Maxm of both no is :" << max <<endl ;
    return 0;
}
*/

/*
Question 7

int main()
{
    int siz;
    cout <<"Enter Size of array :" ;
    cin >> siz ;

    int arr[siz] ;

    cout << "Enter the Elements of array : ";

    for (int i = 0 ; i < siz ; i++)
        cin >> arr[i] ;

    int *ptr = &arr[0];

    cout << "Entered elements in array are : ";

    for (int i = 0 ; i < siz ; i++)
        cout << " " << *(ptr+i) << " "  ;

    return 0;


}
*/

/*
Question 9th
int main()
{
    int *ptr ;

    int num ;

    cout << "Enter The Number of elements in array :";
    cin >> num ;

    ptr = (int *)malloc(num*sizeof (int)) ;

    cout << "ENter the elements of array :" ;

    for (int i = 0 ; i < num ; i++)
        cin >> ptr[i] ;

    int mx = ptr[0] ;

    for (int i = 0 ; i  < num ; i++)
        if (mx <ptr [i]) mx = ptr[i];

    cout << "Max Element is : " << mx << endl;
}
*/

/*
Question 10th -
int main()
{

    string word ;

    cout << "Enter  a WORD : " ;
    cin >> word ;

    char *ptr = &word[0] ;

    int length = 0 ;

    while (*ptr != '\0')
    {
        length++ ;
        ptr++ ;
    }
    cout << "length of word is : " << length << endl;
}
*/

/*
Question 11
void swap(int *ptr1 , int *ptr2)
{
    int temp ;
    temp = *ptr1 ;
    *ptr1 = *ptr2 ;
    *ptr2 = temp ;
}
int main()
{
    int num1 , num2 ;
    cout << "Enter Two numbers :";
    cin >> num1 >> num2 ;
    cout << "Entered Numbers : \n first  :" << num1 <<"\nsecond :" << num2 <<endl ;

    swap(&num1 , &num2);

    cout << "After  Numbers swapped: \n first  :" << num1 <<"\nsecond :" << num2 <<endl ;
}
*/
/*
Question 12
void findfact(int *fact)
{
    int temp = *fact ;
    for ( int i= 1 ; i < temp ; i++ )
        *fact = (*fact)*i;
}

int main()
{
    int fact  ;
    cout << "Enter number to find fact :";
    cin >> fact ;

    findfact(&fact);

    cout << "Result is : " <<fact ;
    return 0 ;
}
*/
/*
Question 13
 int main()
{
	string wrd ;

	cout << "Enter a Word : ";
	cin >> wrd ;

	char *ptr = &wrd[0];

	int nvowel=0 ,ncons = 0 ;

	int i = 0 ;
	while (i < wrd.length())
    {
        if (ptr[i] == 'a' || ptr[i] == 'e' || ptr[i] == 'i' || ptr[i] == 'o' || ptr[i] == 'u') nvowel++ ;

        else ncons++ ;
        i++;
    }

    cout << "No of Vowels :" << nvowel <<endl ;
    cout << "No of Cons :" << ncons <<endl ;

	return 0;
}
*/
/*
Question 15
int * mx(int *num1 , int *num2)
{
    if (*num1 >= *num2) return num1 ;
    else return num2 ;
}

int main()
{
    int num1 , num2 ;

    cout << "Enter Two numbers : ";
    cin >> num1 >> num2 ;

    int *result ;
    result = mx(&num1 , &num2);

    cout << "Max Number is : " << *result << endl ;
    return 0;
}
*/
/*
Question 16
int main()
{
    int siz ;

    cout << "Enter Size of array : " ;
    cin >> siz ;

    int *ptr = (int *)calloc(siz , sizeof(int));

    cout << "Enter Elements of array :" ;
    for (int i = 0 ; i < siz ; i++)
        cin >> ptr[i] ;

    int sum = 0 ;

    for (int i = 0 ; i < siz ; i++)
        sum = sum + *(ptr + i);

    cout << "Sum of Elemens Of array is : " << sum << endl ;
}

*/
/*
//Question 17
int main()
{
    int siz ;

    cout << "Enter Size of array : " ;
    cin >> siz ;

    int *ptr = (int *)calloc(siz , sizeof(int));

    cout << "Enter Elements of array :" ;
    for (int i = 0 ; i < siz ; i++)
        cin >> ptr[i] ;

    cout << "Elemens in reverse order  : " ;
    for (int i = siz -1 ; i >=0; i--)
        cout << ptr[i] << " ";
}
*/

/*
// Question 18

struct stud{

    string firstname ;
    int marks ;
    } ;

int main()
{
    struct stud s1 = {"Vaibhav " , 150};
    struct stud  *ptr = &s1 ;

    cout << "Student Name : " << ptr->firstname << endl ;
    cout << "Student Marks : " << ptr->marks << endl ;
}

*/

/*
Question 19

union stud{

    char *firstname ;
    int marks ;
} ;

int main()
{
    union stud s1;

    s1.firstname = "Vaibhav";
    union stud  *ptr = &s1 ;
    cout << "Student Name : " << ptr->firstname << endl ;
}

*/


/*
Question 20

struct stud
{
char *name;
int marks;
};

int main()
{

	static struct stud s1={"Rajiv",60},s2={"Vaibhav",70},s3={"Akhil",80};
	struct stud(*arr[])={&s1,&s2,&s3};
	struct stud(*(*pt)[3])=&arr;

	cout << " Student Name : " << (**(*pt+1)).name<< endl;

	cout <<" Student Marks :  "<< (*(*pt+1))->marks<< endl;

	return 0;
}

*/

/*
Question 21

int main()
{

    char  ch = 'A' ;
    char *ptr ;
    ptr = &ch ;

    for (int i =65 ; i < (65+26) ; i++)
       {
           cout << *ptr << " " ;
           *ptr = *ptr + 1 ;
       }
}

*/

/*
Question 22


int main()
{
    string st ;

    char *ptr ;

    cout << "Enter a word ";
    cin >> st ;
    ptr = &st[0] ;

    int i = st.length()-1;

    while (i>=0)
    {
        cout << ptr[i] ;
        i--;
    }
}
*/
