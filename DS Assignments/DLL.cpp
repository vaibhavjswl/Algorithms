#include <iostream>
#include<string>
#include<string.h>
#include<stdlib.h>

using namespace std ;


class DLList;

class Node{

        int num ;
        Node *next ;
        Node *prev ;
    public:

        Node(int n )
        {
            num  = n ;
            next = NULL ;
            prev = NULL ;
        }

        Node()
        {
          num =  0 ;
          next = NULL ;
          prev = NULL ;
        }

        friend class DLList ;
};

class DLList{

        Node *head ;
        int length ;

    public:
        DLList()
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
        int reverselist();
        int sortlist();
      int concatenate(DLList &dll2);
      int elementSearch(int &num) ;
      int copyInto(DLList& dll2) ;

      void trim() ;


       DLList* unin(DLList &dll2) ;
       DLList* intersect(DLList &ddl2) ;

    static DLList* mergeList(DLList &dll1 , DLList &dll2) ;
};

void DLList::create(int num = 0)
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
        temp->next->prev = temp ;
    }

        length++ ;

}

void DLList::display()
{
    Node *temp = head ;

    cout << "**********************************************************************************************************\n" <<endl ;

    if (this->head == NULL)
        cout << "Empty list \n" << endl ;

    else{

    while (temp != NULL)
    {
        cout << temp->num ;
        if (temp->next!=NULL) cout<<" <-> ";
        temp = temp->next ;
    }
    }
    cout << "\n\n**********************************************************************************************************\n" <<endl ;

}

void DLList::displayOps()
{
    cout <<"\n Doubly Linked List Operations \n"<<endl ;
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
    cout << "12.Sort the List in ascending order" << endl ;
    cout << "13.Search the DLL for an Element" << endl ;
    cout << "14.Copy DLL-1 into another DLL" << endl ;
    cout << "15.Union of list " << endl;
    cout << "16.intersection of list " << endl;
    cout << "17.Merge 2 Lists Term by Term "<< endl ;
    cout << "18 .Exit"<<endl ;
}

Node* DLList::traverse(Node *temp , int pos)
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


int DLList::get_length()
{
    return this->length ;
}


void DLList::insert_pos(int num, int pos)
{
    Node *newnode = new Node(num) ;

    if (head == NULL)
        head = newnode ;

    else if (pos == 1)
    {
        newnode->next = this->head ;
        newnode->next->prev = newnode  ;
        this->head = newnode ;
    }

    else if (pos == (this->length + 1))
    {
        Node *temp ;

        temp = this->traverse(temp , length) ;

        temp->next = newnode ;
        temp->next->prev = temp ;
    }
    else
    {
        Node *temp1 ;

        temp1 = traverse(temp1 , pos -1);

        newnode->next = temp1->next;
        temp1->next = newnode ;
        newnode->prev = temp1 ;
        newnode->next->prev = newnode ;

        temp1->next = newnode ;

    }

    length++ ;
}

int DLList::delete_pos(int pos)
{

    if (this->head == NULL)
        return -1;

    else if (pos<0 || pos > this->length)
        return -2;

    else if (pos == 1){

        Node *temp = this->head ;

        this->head = temp->next ;
        this->head->prev = NULL ;

        delete temp ;
    }

    else if (pos == this->length){
        Node *temp1 , *temp2 ;

        temp1 = this->traverse(temp1 , pos - 1) ;
        temp2 = temp1->next ;


        temp1->next = NULL ;

        delete temp2 ;
    }

    else {

        Node *temp1 , *temp2 ;

        temp1 = this->traverse(temp1 , pos - 1) ;
        temp2 = temp1->next ;

        temp1->next = temp2->next ;
        temp2->next->prev = temp1 ;

        delete temp2 ;
    }

    length--;

    return 1 ;
}

int DLList::reverselist()
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
            current->prev = forwrd ;
        }
        this->head = current ;

        return 1 ;
        }
}


int DLList::sortlist(){

    Node *temp1 , *temp2 ;
    int tmp = 0 ;


    for (int  i = 0 ; i < this->length - 1 ; i++){

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

int DLList::concatenate(DLList& dll2)
{
    if(this->head == NULL)
            return -1;

    else if (dll2.head == NULL)
            return -2;

    else
        {
            Node *temp = traverse(temp , this->length);

            temp->next = dll2.head;

            temp->next->prev = temp ;

            this->length = this->length + dll2.length ;

            dll2.head = NULL ;

            return 1 ;
        }
}

int DLList::elementSearch(int& num)
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

    }while(temp != NULL);

    if(elementPresent)
        return (indx+1) ;
    else
        return -1 ;
}

int DLList::copyInto(DLList& dll2)
{
    Node *temp = this->head ;

    do
    {
        dll2.create(temp->num);
        temp = temp->next ;
    }while(temp != NULL) ;

    return 1 ;
}

void DLList::trim(){


    Node *templ1  = this->head;
    Node *rmnode ;

    this->sortlist() ;

    while (templ1->next != NULL){

    if(templ1->num == templ1->next->num){

            rmnode = templ1->next ;

            templ1->next = templ1->next->next ;

            templ1->next->prev = templ1 ;

            delete rmnode ;

            this->length-- ;
        }

        else templ1 = templ1->next  ;
    }


}


DLList* DLList::unin(DLList& dll2){

    DLList* dll3 = new DLList();

    Node *templ1 ;
    Node *templ2 ;



    templ1 = this->head ;

    while(templ1!=NULL){
    dll3->create(templ1->num);
    templ1 = templ1->next ;
    }

    templ2 = dll2.head ;
    while (templ2!=NULL)
    {
        dll3->create(templ2->num) ;
        templ2 = templ2->next;
    }

    dll3->sortlist() ;
    dll3->trim() ;

    return dll3 ;
}

DLList* DLList::intersect(DLList& dll2)
{
    DLList* dll3 = new DLList();

    Node *templ1 ;
    Node *templ2 ;

    for (templ1 = this->head  ; templ1!=NULL ; templ1 = templ1->next)
    {

        for (templ2 = dll2.head  ; templ2!=NULL ; templ2 = templ2->next)
        {
           if (templ1->num == templ2->num)
            {
                dll3->create(templ1->num) ;
                break ;
            }
        }

    }
    dll3->sortlist() ;
    return dll3 ;
}

DLList* DLList::mergeList(DLList &dll1 , DLList &dll2){

DLList* mergeddll = new DLList();

Node *temp1 , *temp2;

temp1 = dll1.head ;
temp2 = dll2.head ;

int ratio1 , ratio2 ;

cout << "Enter the ration separated by space in whole numbers in which to merger DLL : ";
cin>>ratio1>>ratio2;


while (temp1!=NULL && temp2!=NULL ){

        int k = 0 , m = 0 ;

    while(temp1!=NULL && k < ratio1){
        mergeddll->create(temp1->num );
        temp1 = temp1->next ;
        k++;
    }
        while(temp2!=NULL && m < ratio2){
        mergeddll->create(temp2->num);
        temp2 = temp2->next ;
        m++;
    }
}

while (temp1 != NULL){
    mergeddll->create(temp1->num) ;
    temp1 = temp1->next;
}


while (temp2 != NULL){
    mergeddll->create(temp2->num) ;
    temp2 = temp2->next;
}


return mergeddll ;

}


int main()
{

    DLList dll1 ;

    int choice ;
    char exit = 'n' ;

    do
    {
        DLList::displayOps();
        cout << "Your Choice : " << endl ;
        cin >> choice ;


        switch(choice)
        {
                case 1:
                    {
                            char en = 'y';
                            int num ;

                            cout << "Enter Nodes OF DLL-1" <<endl ;

                            while (en == 'y' || en == 'Y'){
                                cout << "Enter Number : ";
                                cin >> num;

                                dll1.create(num) ;
                                cout << "Do you wish to create another node (y or n): ";
                                cin >> en ;
                            }
                    }
                                break ;

                case 2 :
                                cout <<"DLL - 1"<<endl ;
                                dll1.display();
                                break ;

                case 3 :
                            {

                                int num ;
                                cout << "Enter Number : " ;
                                cin >> num ;

                                dll1.insert_pos(num , 1) ;
                                cout << "Node Successfully inserted  at Beginning \n" << endl ;
                            }
                                break ;


                case 4 :
                            {
                                int num ;
                                cout << "Enter Number : " ;
                                cin >> num ;

                                dll1.insert_pos(num , dll1.get_length()+1 ) ;
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

                                dll1.insert_pos(num, pos);
                                cout << "Node Successfully inserted  at pos :  " << pos<< endl ;
                            }
                                break ;

                case 6 :
                            cout << "Length of the list is : "<< dll1.get_length() << endl ;
                            break;

                case 7 :
                        {
                            int flag_del = 0 ;
                            flag_del = dll1.delete_pos(1) ;

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
                            flag_del = dll1.delete_pos(dll1.get_length()) ;

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

                            flag_del = dll1.delete_pos(pos) ;

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
                          rev_flag = dll1.reverselist();

                          if (rev_flag == 1){
                                cout <<"Reversing List Successfull" << endl ;
                                cout <<"Reversed DLL-1"<<endl ;
                                dll1.display() ;
                                }
                          else
                            cout << "Reversing list failed .Error occured " << endl ;

                          break;

                        }

                case 11 :
                        {
                            DLList dll2;

                            char en = 'y';
                            int num ;

                            cout << "Enter Nodes OF 2nd Linked List" <<endl ;

                            while (en == 'y' || en == 'Y'){
                                cout << "Enter Number : ";
                                cin >> num;

                                dll2.create(num) ;

                                cout << "Do you wish to create another node (y or n): ";
                                cin >> en ;
                            }

                            cout << "DLL - 1 : "<<endl;
                            dll1.display();

                            cout << "DLL - 2 : "<<endl;
                            dll2.display();

                            dll1.concatenate(dll2);

                            cout << "Concatenated SLL-1 ( with SLL-2 )"<<endl ;
                            dll1.display() ;
                            break ;
                        }

                case 12 :
                    {
                        int sort_flag = 0 ;

                        sort_flag = dll1.sortlist() ;

                        if (sort_flag == 1)
                            cout << "List successfully sorted" << endl ;

                        else
                            cout << "Error while sorting";
                        break;

                    }
                case 13 :

                  {
                        int element ;
                        cout << "Enter the number to search : ";
                        cin >> element ;

                        int search_flag = 0 ;
                        search_flag = dll1.elementSearch(element);

                        if(search_flag != -1)
                            cout << "Entered Elements Found in DLL - 1 at Position :" << search_flag <<endl;
                        else
                            cout <<"Entered Element Not found in DLL -1 linked list " << endl ;

                        break ;
                    }


                case 14 :
                    {
                        DLList dll3 ;

                        cout << "DLL - 1 : "<< endl ;
                        dll1.display() ;

                        cout << "DLL-1 IS COPIED INTO DLL-3" << endl;

                        int copy_flag = 0 ;
                        copy_flag = dll1.copyInto(dll3);

                        if(copy_flag==1)
                        {
                            cout << "DLL-3 : "<<endl ;
                            dll3.display();
                        }
                        else
                            cout << "Copying Failed Error Occured" << endl ;

                        break ;
                    }

                case 15 :
                    {
                            DLList dll3;


                            char en = 'y';
                            int num ;
                            cout << "Enter Nodes OF 2nd DLL" <<endl ;

                            while (en == 'y' || en == 'Y'){
                                cout << "Enter Number : ";
                                cin >> num;

                                dll3.create(num ) ;

                                cout << "Do you wish to create another node (y or n): ";
                                cin >> en ;
                            }

                            cout << "DLL - 1 : "<<endl;
                            dll1.display();

                            cout << "DLL - 3 : "<<endl;
                            dll3.display();

                            DLList *unlist  = dll1.unin(dll3);

                            cout << "Union Of DLL-1 and DLL-2  : " << endl;
                            unlist->display();
                            break ;
                    }

                case 16 :
                     {
                            DLList dll3;


                            char en = 'y';
                            int num ;
                            cout << "Enter Nodes OF 2nd DLL" <<endl ;

                            while (en == 'y' || en == 'Y'){
                                cout << "Enter Number : ";
                                cin >> num;

                                dll3.create(num) ;

                                cout << "Do you wish to create another node (y or n): ";
                                cin >> en ;
                            }

                            cout << "DLL - 1 : "<<endl;
                            dll1.display();

                            cout << "DLL - 3 : "<<endl;
                            dll3.display();

                            DLList *intersectlist  = dll1.intersect(dll3);

                            cout << "Intersection of DLL-1 and DLL-3 : " << endl;
                            intersectlist->display();
                            break ;
                    }


                case 17 :
                    {

                        DLList dll3;


                        char en = 'y';
                        int num ;
                        cout << "Enter Nodes OF 2nd DLL" <<endl ;

                        while (en == 'y' || en == 'Y'){
                            cout << "Enter Number : ";
                            cin >> num;

                            dll3.create(num) ;

                            cout << "Do you wish to create another node (y or n): ";
                            cin >> en ;
                            }

                        cout << "DLL - 1 : "<<endl;
                        dll1.display();

                        cout << "DLL - 3 : "<<endl;
                        dll3.display();

                        DLList *mergedList  = DLList::mergeList(dll1 , dll3);

                        cout << "Intersection of DLL-1 and DLL-3 : " << endl;
                        mergedList->display();

                        break ;
                    }

                case 18 :
                                exit = 'y';
                                break ;

                case 19 :
                                system("CLS");
                                break;


                default:
                            cout <<"Wrong choice enter again " << endl ;

        }
    }while (exit != 'y' && exit !='Y');

}
