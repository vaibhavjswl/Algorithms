#include <iostream>
#include<string>
#include<string.h>
#include<stdlib.h>

using namespace std ;


class SLList;

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

        friend class SLList ;
};

class SLList{

        Node *head ;
        int length ;

    public:
        SLList()
        {
                head = NULL ;
                length = 0;
        }

        void create(int num);
        void display();
        static void displayOps();
        Node* traverse(Node * , int ) ;
        void insert_pos(int num , int pos);
        int  delete_pos(int pos);
        int reverselist();
        int concatenate(SLList &sll2);

        int get_length() ;
        int sortlist();

        SLList* unin(SLList &l2) ;
        SLList* intersect(SLList &l2) ;
};

void SLList::create(int num = 0)
{

    Node *newnode = new Node(num) ;
    Node *temp ;


    if (head == NULL )
        head = newnode ;
    else
    {
        temp = head ;

        while (temp->next != NULL)
            temp = temp->next ;

        temp->next = newnode ;
    }

        length++ ;

}

void SLList::display()
{
    Node *temp = head ;

    cout << "**********************************************************************************************************\n" <<endl ;

    if (this->head == NULL)
        cout << "Empty list \n" << endl ;

    else{

    while (temp != NULL)
    {
        cout << temp->num ;
        if (temp->next!=NULL) cout<<" -> ";
        temp = temp->next ;
    }
    }
    cout << "\n\n**********************************************************************************************************\n" <<endl ;

}

void SLList::displayOps()
{
    cout <<"\nSingle Linked List Operations \n"<<endl ;
    cout << "1. Add a Node " << endl ;
    cout << "2. Display list " << endl ;
    cout << "3. Insert NODE at Beginning " << endl ;
    cout << "4. Insert NODE at END " << endl ;
    cout << "5. Insert NODE at Entered Position " << endl ;
    cout << "6. Display THe Length of list " << endl ;
    cout << "7. Delete The First Node of List" << endl ;
    cout << "8. Delete The Last Node of List" << endl ;
    cout << "9. Delete The Node at given position of the List" << endl ;
    cout << "10.Reverse the linked list" << endl ;
    cout << "11.Concatenate list " << endl ;
    cout << "12. Sort the List in ascending order" << endl ;
    cout << "13. Union of list " << endl;
    cout << "14. intersection of list " << endl;
    cout << "15 . Exit " << endl ;
}

Node* SLList::traverse(Node *temp , int pos)
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


int SLList::get_length()
{
    return this->length ;
}


void SLList::insert_pos(int num, int pos)
{
    Node *newnode = new Node(num) ;

    if (head == NULL)
        head = newnode ;

    else if (pos == 1)
    {
        newnode->next = this->head ;
        this->head = newnode ;
    }

    else if (pos == (this->length + 1))
    {
        Node *temp ;

        temp = this->traverse(temp , length) ;

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

int SLList::delete_pos(int pos)
{

    if (this->head == NULL)
        return -1;

    else if (pos<0 || pos > this->length)
        return -2;

    else if (pos == 1){

        Node *temp = this->head ;

        this->head = temp->next ;

        delete temp ;
    }

    else if (pos == this->length){
        Node *temp1 , *temp2 ;

        temp2 = this->traverse(temp2 , pos) ;
        temp1 = this->traverse(temp1 , pos - 1) ;

        temp1->next = NULL ;

        delete temp2 ;
    }

    else {

        Node *temp1 , *temp2 ;

        temp2 = this->traverse(temp2 , pos) ;
        temp1 = this->traverse(temp1 , pos - 1) ;

        temp1->next = temp2->next ;

        delete temp2 ;
    }

    length--;

    return 1 ;
}

int SLList::reverselist()
{
    if (this->head == NULL)
                return -1 ;

    else if (this->length == 1)
                return -2 ;

    else{
        Node *forwrd , *current , *previous ;

        forwrd = this->head ;
        current = NULL ;

        while (forwrd != NULL)
        {
            previous = current ;
            current = forwrd ;
            forwrd  = forwrd->next ;
            current->next = previous;
        }
        this->head = current ;

        return 1 ;
        }
}

int SLList::concatenate(SLList& sll2)
{
    if(this->head == NULL)
            return -1;

    else if (sll2.head == NULL)
            return -2;

    else
        {
            Node *temp = traverse(temp , this->get_length());

            temp->next = sll2.head;

            this->length = this->length + sll2.length ;

            sll2.head = NULL ;

            return 1 ;
        }
}

int SLList::sortlist(){

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

SLList* SLList::unin(SLList& l2){

    SLList* l3 = new SLList();

    Node *templ1 ;
    Node *templ2 ;


    int flag = 0 ;

    for (templ1 = this->head  ; templ1!=NULL ; templ1 = templ1->next)
    {
        flag = 0 ;
        for (templ2 = l2.head  ; templ2!=NULL ; templ2 = templ2->next)
        {
            if (templ1->num == templ2->num)
            {
                flag = 1 ;
                break ;
            }
        }

        if ( flag == 0 )
        {
            l3->create(templ1->num) ;
        }
    }
    templ2 = l2.head ;

    while (templ2!=NULL)
    {
        l3->create(templ2->num) ;
        templ2 = templ2->next;
    }


    return l3 ;
}

SLList* SLList::intersect(SLList& l2)
{
    SLList* l3 = new SLList();

    Node *templ1 ;
    Node *templ2 ;


    for (templ1 = this->head  ; templ1!=NULL ; templ1 = templ1->next)
    {

        for (templ2 = l2.head  ; templ2!=NULL ; templ2 = templ2->next)
        {
           if (templ1->num == templ2->num)
            {
                l3->create(templ1->num) ;
                break ;
            }
        }

    }
    return l3 ;
}
int main()
{

    SLList sll ;

    int choice ;
    char exit = 'n' ;

    do
    {
        SLList::displayOps();
        cout << "Your Choice : " << endl ;
        cin >> choice ;


        switch(choice)
        {
                case 1:
                            {
                                int num ;
                                cout << "Enter Number : " ;
                                cin >> num ;

                                sll.create(num);
                                cout << "Node Successfully created " << endl ;
                            }
                                break ;

                case 2 :
                                cout <<"SLL - 1"<<endl ;
                                sll.display();
                                break ;

                case 3 :
                            {

                                int num ;
                                cout << "Enter Number : " ;
                                cin >> num ;

                                sll.insert_pos(num , 1) ;
                                cout << "Node Successfully inserted  at Beginning \n" << endl ;
                            }
                                break ;


                case 4 :
                            {
                                int num ;
                                cout << "Enter Number : " ;
                                cin >> num ;

                                sll.insert_pos(num , sll.get_length()+1 ) ;
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

                                sll.insert_pos(num, pos);
                                cout << "Node Successfully inserted  at pos :  " << pos<< endl ;
                            }
                                break ;

                case 6 :
                            cout << "Length of the list is : "<< sll.get_length() << endl ;
                            break;

                case 7 :
                        {
                            int flag_del = 0 ;
                            flag_del = sll.delete_pos(1) ;

                            if (flag_del == 1)
                                cout <<"Starting Node successfully deleted " <<endl ;

                            else if (flag_del == -1)
                                cout << "List Empty . Delete operaion Cannout be performed" << endl;
                            else
                                cout << "Unknown error detected" << endl ;

                            break ;
                        }

                case 8 :
                        {
                            int flag_del = 0 ;
                            flag_del = sll.delete_pos(sll.get_length()) ;

                            if (flag_del == 1)
                                cout <<"Ending Node successfully deleted " <<endl ;

                            else if (flag_del == -1)
                                cout << "List Empty . Delete operation Cannot be performed" << endl;
                            else
                                cout << "Unknown error detected" << endl ;
                            break ;
                        }

                case 9 :
                        {
                            int flag_del = 0 , pos;
                            cout << "Enter Position of node which to delete : " ;
                            cin >> pos ;

                            flag_del = sll.delete_pos(pos) ;

                            if (flag_del == 1)
                                cout <<" Node  at position : " << pos << " successfully deleted " <<endl ;

                            else if (flag_del == -1)
                                cout << "List Empty . Delete operaion Cannout be performed" << endl;
                            else if (flag_del == -2)
                                cout << "Error occured . Entered Position is out of bounds of List ." << endl;
                            else
                                cout << "Unknown error detected" << endl ;
                            break ;
                        }

                case 10 :
                        {
                          int rev_flag = 0 ;
                          rev_flag = sll.reverselist();

                          if (rev_flag == 1)
                                cout <<"Reversing List Successfull" << endl ;
                          else
                            cout << "Reversing list failed .Error occured " << endl ;

                          break;

                        }

                case 11 :
                        {
                            SLList sll2;

                            char en = 'y';
                            int num ;
                            string nam ;
                            cout << "Enter Nodes OF 2nd Linked List" <<endl ;

                            while (en == 'y' || en == 'Y'){
                                cout << "Enter Number : ";
                                cin >> num;

                                sll2.create(num) ;

                                cout << "Do you wish to create another node (y or n): ";
                                cin >> en ;
                            }

                            cout << "SLL - 1 : "<<endl;
                            sll.display();

                            cout << "SLL - 2 : "<<endl;
                            sll2.display();

                            sll.concatenate(sll2);

                            cout << "Concatenated SLL-1 ( with SLL-2 )"<<endl ;
                            sll.display() ;
                            break ;
                        }

                case 12 :
                    {
                        int sortflag = 0 ;

                        sortflag = sll.sortlist() ;

                        if (sortflag == 1)
                            cout << "List successfully sorted" << endl ;

                        else
                            cout << "Error while sorting";
                        break;

                    }

                case 13 :
                    {
                            SLList sll3;


                            char en = 'y';
                            int num ;
                            cout << "Enter Nodes OF 2nd Linked List" <<endl ;

                            while (en == 'y' || en == 'Y'){
                                cout << "Enter Number : ";
                                cin >> num;

                                sll3.create(num ) ;

                                cout << "Do you wish to create another node (y or n): ";
                                cin >> en ;
                            }

                            cout << "SLL - 1 : "<<endl;
                            sll.display();

                            cout << "SLL - 2 : "<<endl;
                            sll3.display();

                            SLList *unlist  = sll.unin(sll3);

                            cout << "Union Of SLL-1 and SLL-2  : " << endl;
                            unlist->display();
                            break ;
                    }

                case 14 :
                     {
                            SLList sll3;


                            char en = 'y';
                            int num ;
                            cout << "Enter Nodes OF 2nd Linked List" <<endl ;

                            while (en == 'y' || en == 'Y'){
                                cout << "Enter Number : ";
                                cin >> num;

                                sll3.create(num) ;

                                cout << "Do you wish to create another node (y or n): ";
                                cin >> en ;
                            }

                            cout << "SLL - 1 : "<<endl;
                            sll.display();

                            cout << "SLL - 2 : "<<endl;
                            sll3.display();

                            SLList *intersectlist  = sll.intersect(sll3);

                            cout << "Intersection of SLL-1 and SLL-2 : " << endl;
                            intersectlist->display();
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
