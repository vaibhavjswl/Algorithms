#include<iostream>
#include <string>  
using namespace std ;


class HashTable{

    int table[100][2] ;
    int buckets ;

    public:

    HashTable(){
    buckets = 2 ;
    for (int i=0 ; i < 100 ; i++){
        for(int j = 0 ; j < 2 ; j++){
            table[i][0] = -63200 ;
            table[i][1] = -1 ;
        }
    }
}

void printTable(){
    cout << "Hashtable with Chaining" << endl ; 
    cout << "index    num    chain" << endl ; 
    for (int i=0 ; i < 100 ; i++){

        cout << "  "<<i <<".      " ;
         for(int j = 0 ; j < 2 ; j++){
        if(table[i][j] > -1)
            cout <<table[i][j] << "      " ;
        else
        {
            cout << "-1" << "      " ; 
        }
    }
    cout << "\n" ;
    }
}


static int hashf(int num){
    return (num%100) ;
}

void putele(long int num){
    bool inserted = false ;
    int indx = HashTable::hashf(num);

   if (table[indx][1]==-1 && table[indx][0]==-63200){

       table[indx][0]= num ; 
   }

   else if (table[indx][1]==-1 && table[indx][0]!=-63200){
       int previndx= indx ; 
       int chindx=indx ; 

       for(int i = indx+1 ; i < 100 ; i++){

           if(table[i][1]==-1 && table[i][0]==-63200){
               table[i][0]=num ;
               table[indx][1]= i;
               chindx=i ;
               break ; 
           }
       }
   }

   else if (table[indx][1]!=-1){
       int previndx= indx ; 
       int chindx=indx ; 
       bool inserted = false ;

       previndx = table[indx][1] ;

       while(!inserted){
           if(table[previndx][1]==-1 && table[previndx][0]!=-63200){
                for(int i = previndx+1 ; i < 100 ; i++){
                    if(table[i][1]==-1 && table[i][0]==-63200){
                        table[i][0]=num ;
                        table[previndx][1]= i;
                        inserted=true ;
                        break ; 
                    }
                }
            }

            else if(table[previndx][1]!=-1 && table[previndx][0]!=-63200){
                previndx = table[previndx][1] ;
            }
       }
   }
}


};
int main(){

    HashTable t ;

    cout << "Inserting Elements : 1" << endl ; 
    t.putele(1) ;
     cout << "Inserting Elements :20" << endl ; 
    t.putele(20) ;
     cout << "Inserting Elements : 420" << endl ; 
    t.putele(420) ;
     cout << "Inserting Elements : 220" << endl ; 
    t.putele(221) ;
     cout << "Inserting Elements : 120" << endl ; 
    t.putele(120) ;
     cout << "Inserting Elements : 111" << endl ; 
    t.putele(111) ;
    
    t.printTable() ;
}
