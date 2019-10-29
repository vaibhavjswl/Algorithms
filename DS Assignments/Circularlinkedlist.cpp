#include <iostream>
#include<string>
#include<string.h>
#include<stdlib.h>

using namespace std ;


class CLList;

class Node{

        int num ;
        Node *next ;
    public:

        Node(int n )
        {
            num  = n ;
            next = NULL ;
        }

        Node()
        {
          num =  0 ;
          next = NULL ;
        }

        friend class CLList ;
};

class CLList{

        Node *head ;
        int length ;

    public:
        CLList()
        {
                head = NULL ;
                length = 0;
        }

        void create(int num);
        void display();
        static void displayOps();
        Node* traverse(Node * , int ) ;
        int get_length() ;
        void insert_pos(int num , int pos);
        int  delete_pos(int pos);
        int sortlist();
        int reverselist();
        int concatenate(CLList &cll2);
        int elementSearch(int &num) ;
        int copyInto(CLList& cll2) ;
};

void CLList::create(int num = 0)
{

    Node *newnode = new Node(num) ;


    if (head == NULL )
        {
            head = newnode ;
            head->next = head ;
        }

    else
    {
        Node *temp = this->head ;

        while (temp->next != this->head)
            temp = temp->next ;

        newnode->next = this->head ;
        temp->next = newnode ;

    }

        length++ ;

}

void CLList::display()
{
    Node *temp = this->head ;

    cout << "**********************************************************************************************************\n" <<endl ;

    if (this->head == NULL || this->length == 0)
        cout << "Empty list \n" << endl ;

    else
    {

        do{
            cout << temp->num;
            if (!(temp->next == this->head))
            cout << " -> ";
            temp = temp->next ;
     }while (temp != this->head) ;

    if(this->length > 1 )
    {
        cout << '\n' << '^' ;
        for(int j = 0 ; j < (((this->length - 1 )*4) + (this->length-2)) ; j++)
            cout << " ";

        cout <<"|";
        cout << '\n' ;

        for(int j = 0 ; j < (((this->length - 1 )*4) + (this->length-2)) ; j++)
            {
                if(j==0)
                    cout << "|";
                else
                    cout <<"_";
        }
        cout << "_|";
    }

    cout << "\n\n**********************************************************************************************************\n" <<endl ;
    }
}

void CLList::displayOps()
{
    cout << "Circular Link List Operations \n"<<endl ;
    cout << "1.Add a Node " << endl ;
    cout << "2.Display list " << endl ;
    cout << "3.Insert NODE at Beginning " << endl ;
    cout << "4.Insert NODE at END " << endl ;
    cout << "5.Insert NODE at Entered Position " << endl ;
    cout << "6.Display THe Length of list " << endl ;
    cout << "7.Delete The First Node of List" << endl ;
    cout << "8.Delete The Last Node of List" << endl ;
    cout << "9.Delete The Node at given position of the List" << endl ;
    cout << "10.Sort the List in ascending order" << endl ;
    cout << "11.Reverse the linked list" << endl ;
    cout << "12.Concatenate list 1 with list 2 " << endl ;
    cout << "13.Search The CLL For an Element " << endl ;
    cout << "14.Copy CLL into Another CLL" << endl ;
    cout << "15.Exit " << endl ;
}

Node* CLList::traverse(Node *temp , int pos)
{
    int i = 1 ;
    temp = head ;

    while (i < pos)
    {
        temp = temp->next ;
        i++;
    }
    return temp ;
}


int CLList::get_length()
{
    return this->length ;
}


void CLList::insert_pos(int num, int pos)
{
    Node *newnode = new Node(num) ;

    if (head == NULL)
    {
        head = newnode ;
        head->next = head ;
    }

    else if (pos == 1)
    {
        Node *temp = traverse(temp , this->length) ;

        newnode->next = this->head ;
        this->head = newnode ;
        temp->next = this->head ;

    }

    else if (pos == (this->length + 1))
    {
        Node *temp ;

        temp = this->traverse(temp , length) ;

        newnode->next = this->head ;
        temp->next = newnode ;
    }
    else
    {
        Node *temp1 , *temp2 ;

        temp1 = traverse(temp1 , pos -1);
        temp2 = traverse(temp2 , pos);

        newnode->next = temp2 ;

        temp1->next = newnode ;

    }

    length++ ;
}

int CLList::delete_pos(int pos)
{

    if (this->head == NULL)
        return -1;

    else if (pos<0 || pos > this->length)
        return -2;

    else if (pos == 1){

        Node *temp = this->head ;
        Node *temp2 = traverse(temp2 , this->length) ;

        this->head = temp->next ;
        temp2->next = this->head ;

        delete temp ;
    }

    else {

        Node *temp1 , *temp2 ;

        temp1 = this->traverse(temp1 , pos - 1) ;
        temp2 = this->traverse(temp2 , pos) ;

        temp1->next = temp2->next ;

        delete temp2 ;
    }

    length--;

    return 1 ;
}

int CLList::sortlist(){

    Node *temp1 , *temp2 ;
    int tmp = 0 ;


    for (int  i = 0 ; i < this->length -1 ; i++){

            temp1 = this->head ;
            temp2 = this->head->next ;

        for (int j = 0 ; j < this->length-i-1 ; j++){

            if (temp1->num > temp2->num){
                    tmp = temp1->num ;
                    temp1->num = temp2->num ;
                    temp2->num = tmp ;
            }

            temp1 = temp1->next ;
            temp2 = temp2->next ;
        }
    }

    return 1;
}

int CLList::reverselist()
{
    if (this->head == NULL)
                return -1 ;

    else if (this->length == 1)
                return -2 ;

    else{
        Node *forwrd , *current , *previous ;

        forwrd = this->head ;
        current = NULL ;

        do
        {
            previous = current ;
            current = forwrd ;
            forwrd  = forwrd->next ;
            current->next = previous;
        }while (forwrd != this->head);

        this->head = current ;
        forwrd->next = this->head;

        return 1 ;
        }
}


int CLList::concatenate(CLList& cll2)
{
    if(this->head == NULL)
            return -1;

    else if (cll2.head == NULL)
            return -2;

    else
        {
            Node *temp = traverse(temp , this->get_length());

            temp->next = cll2.head;

            this->length = this->length + cll2.length ;

            do{
                temp = temp->next ;
            }while(temp->next != cll2.head);


            temp->next = this->head ;

            cll2.head = NULL ;

            return 1 ;
        }
}

int CLList::elementSearch(int& num)
{
    Node *temp = this->head ;
    int indx = 0 ;
    bool elementPresent = false ;
    do
    {
        if(temp->num == num )
        {
            elementPresent = true ;
            break ;
        }

        indx ++ ;
        temp = temp->next ;

    }while(temp != this->head);

    if(elementPresent)
        return (indx+1) ;
    else
        return -1 ;
}

int CLList::copyInto(CLList& cll2)
{
    Node *temp = this->head ;

    do
    {
        cll2.create(temp->num);
        temp = temp->next ;
    }while(temp != this->head ) ;

    return 1 ;
}


int main()
{

    CLList cll1 ;

    int choice ;
    char exit = 'n' ;

    do
    {
        CLList::displayOps();
        cout << "Your Choice : " << endl ;
        cin >> choice ;


        switch(choice)
        {
                case 1:
                            {
                                int num ;
                                cout << "Enter Number : " ;
                                cin >> num ;

                                cll1.create(num);
                                cout << "Node Successfully created " << endl ;
                            }
                                break ;

                case 2 :
                                cll1.display();
                                break ;

                case 3 :
                            {

                                int num ;
                                cout << "Enter Number : " ;
                                cin >> num ;

                                cll1.insert_pos(num , 1) ;
                                cout << "Node Successfully inserted  at Beginning \n" << endl ;
                                cout << cll1.get_length() ;
                            }
                                break ;


                case 4 :
                            {
                                int num ;
                                cout << "Enter Number : " ;
                                cin >> num ;

                                cll1.insert_pos(num , cll1.get_length()+1 ) ;
                                cout << "Node Successfully inserted  at END \n" << endl ;
                            }
                                break ;

                case 5 :

                            {
                                int num ;
                                cout << "Enter Number : " ;
                                cin >> num ;
                                int pos ;

                                cout << "Enter the position where you want to insert node : ";
                                cin>> pos;

                                cll1.insert_pos(num, pos);
                                cout << "Node Successfully inserted  at pos :  " << pos<< endl ;
                            }
                                break ;

                case 6 :
                        {
                            cout <<"Length of Circular Linked list is : " << cll1.get_length() << endl ;
                            break;
                        }

                case 7 :
                        {
                            int del_flag = 0 ;

                            del_flag = cll1.delete_pos(1) ;

                            if (del_flag == 1 )
                                cout << "starting node successfully deleted \n" << endl;

                            else if (del_flag == -1 )
                                cout << "Circular link List empty . cannot delete anything\n" << endl;

                            break ;
                        }

                case 8 :
                        {
                            int del_flag = 0 ;

                            del_flag = cll1.delete_pos(cll1.get_length()) ;

                            if (del_flag == 1 )
                                cout << "Lasr  node successfully deleted \n" << endl;

                           else if (del_flag == -1 )
                                cout << "Circular link List empty . cannot delete anything\n" << endl;

                            break ;
                        }

                case 9 :
                        {
                            int del_flag = 0 ;
                            int pos ;

                            cout << "Enter position of Node you want to delete : " ;
                            cin >> pos ;

                            del_flag = cll1.delete_pos(pos) ;

                            if (del_flag == 1 )
                                cout << "starting node successfully deleted \n" << endl;

                            else if (del_flag == -1 )
                                cout << "Circular link List empty . cannot delete anything\n" << endl;

                            else if (del_flag == -2)
                                cout << "Entered Position out of Bounds of circular list . Please enter again\n" <<endl ;

                            break ;
                        }

                case 10 :
                    {
                         int sort_flag = cll1.sortlist() ;

                         if (sort_flag == 1)
                            cout << "Circular List successfully sorted \n" << endl ;
                        break ;
                    }


                case 11 :
                    {
                        int rev_flag = 0;

                        cout <<"CLL  to be reversed : " << endl ;
                        cll1.display();


                        rev_flag = cll1.reverselist() ;
                        if(rev_flag == 1)
                        {
                            cout << "Reversing List Successfull \n" <<endl ;
                            cout << "CLL after Reversing : " << endl ;
                            cll1.display() ;
                        }
                        else
                            cout << "Reversing Failed .Error occured " << endl ;


                        break ;
                    }

                case 12:
                    {
                        CLList cll2 ;

                        char ext = 'y';
                        int num ;

                        cout << "Enter Elements of CLL - 2 :"<<endl ;

                        while(ext =='y' || ext=='Y')
                        {
                            cout << "Enter Number ";
                            cin>> num ;

                            cll2.create(num);

                            cout << "Do you want to enter another number (y/n) :  ";
                            cin >> ext ;
                        }

                        cout << "CLL-1 : " <<endl ;

                        cll1.display();

                        cout << "CLL- 2 : " <<endl ;

                        cll2.display() ;

                        cout << "CLL-1 Concatenated with CLL- 2 : " << endl ;
                        cll1.concatenate(cll2) ;

                        cll1.display() ;

                        break;

                    }

                case 13:
                    {
                        int element ;
                        cout << "Enter the number to search : ";
                        cin >> element ;

                        int search_flag = 0 ;
                        search_flag = cll1.elementSearch(element);

                        if(search_flag != -1)
                            cout << "Entered Elements Found in Circular Linked List at Position :" << search_flag <<endl;
                        else
                            cout <<"Entered Element Not found in circular linked list " << endl ;

                        break ;
                    }

                case 14 :
                    {
                        CLList cll3 ;

                        cout << "CLL - 1 : "<< endl ;
                        cll1.display() ;

                        cout << "CLL-1 IS COPIED INTO CLL-3" << endl;

                        int copy_flag = 0 ;
                        copy_flag = cll1.copyInto(cll3);

                        if(copy_flag==1)
                        {
                            cout << "CLL-2 : "<<endl ;
                            cll3.display();
                        }
                        else
                            cout << "Copying Failed Error Occured" << endl ;

                        break ;
                    }

                case 15 :
                                exit = 'y';
                                break ;

                case 16:
                                system("CLS");
                                break;


                default:
                            cout <<"Wrong choice enter again " << endl ;

        }

    }while (exit != 'y' && exit !='Y');

}
