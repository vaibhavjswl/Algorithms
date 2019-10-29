#include<iostream>
#include <string>  
using namespace std ;


class HashTable{

    int table[25][2] ;

    public:

    HashTable(){
    for (int i=0 ; i < 25 ; i++){
        for(int j = 0 ; j < 2 ; j++){
            table[i][0] = -63200 ;
            table[i][1] = -63200 ;
        }
    }
}

void printTable(){
    cout << "HashTable with Quadratic probing" <<endl ;
    cout << "index  bucket1 bucket2" << endl ;
    for (int i=0 ; i < 25 ; i++){
        
        cout <<"  "<< i << ".   ";

        for(int j = 0 ; j < 2 ; j++){ 
            if(table[i][j] !=-63200)
                cout << table[i][j] << "        " ;
            else
            {
                cout << "-1" << "        " ; 
            }
        }
        cout << "\n" ;
    }
}

static int hashf(int num){
    return (num%25) ;
}

void putele(long int num){
    bool inserted = false ;
    int indx;
    int i = 0 ; 
    int quadvar ;
    while(!inserted){

        quadvar = (i*i)%25 ;
        indx = HashTable::hashf(num + quadvar) ;

        if (indx >=25 || indx < 0 ){
            break ; 
        }
        if(table[indx][0] ==-63200){
            table[indx][0] = num ;
            inserted = true ;  
        }
        else if (table[indx][1]==-63200){
            table[indx][1]=num ;
            inserted = true ;  
        }

        if(!inserted)
                i = i+2 ; 
    };

    if(!inserted)
        cout << "Element cannot be inserted ." << endl ;
}

};
int main(){

    HashTable t ;


    t.putele(1) ;
    t.putele(26) ;
    t.putele(126) ;
    t.putele(526) ;
    t.putele(626) ;
    t.putele(426) ;
    t.putele(626) ;

    t.printTable() ;

}
