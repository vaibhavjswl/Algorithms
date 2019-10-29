#include<iostream>
#include <sstream>  // for string streams
#include <string>  // for string
using namespace std ;

class Node{

    long int data ; 
    Node *next ;
    public:
    Node(){
        this->data = -1;
        this->next = NULL ;
    } 

    Node(long int num){
        this->data = num ; 
        this->next = NULL ; 
    }

    friend class HashTable ;
};

class HashTable{

    Node* table[25] ;

    public:
    HashTable(){
    for (int i=0 ; i < 25 ; i++){
        table[i] = NULL ; 
    }
}

void printTable(){
       cout <<"Hashtable with Chaining wih Linkedlist" << endl ; 
       cout << "index   Elements"<<endl ;
       for (int i=0 ; i < 25 ; i++){
           cout << "  " << i << ".      ";

        
            if(table[i] !=NULL){
                Node *temp = table[i] ;
                do{
                    cout << temp->data << "  " ; 
                    temp = temp->next ; 
                }
                while(temp != NULL) ;
            }
            else
            {
                cout << "  " ; 
            }
           
           cout << "\n" ;
       }
    }

static int hashf(int num){
    return (num%25) ;
}

void putele(long int num){

    Node *newnode = new Node(num) ; 
    bool inserted = false ;
    int indx = HashTable::hashf(num);

    if (table[indx] == NULL){
        table[indx] = newnode;
    }

    else{
        Node *temp = table[indx] ;

        while(temp->next!=NULL){
            temp = temp->next ;
        }
        temp->next = newnode ; 
    }
            
}
};
int main(){

    HashTable t ;

    t.putele(1) ;
    t.putele(20) ;
    t.putele(120) ;
    t.putele(21) ;
    t.putele(20) ;
    t.putele(1) ;
    t.putele(540) ;
    t.putele(250) ;
    t.putele(21) ;
    t.putele(20) ;
    t.putele(1) ;
    t.putele(99) ;
    t.putele(77) ;
    t.putele(86) ;
    t.putele(11) ;
    
    t.printTable() ;
}
