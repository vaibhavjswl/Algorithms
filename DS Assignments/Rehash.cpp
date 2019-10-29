#include<iostream>
#include <string>  
using namespace std ;


class HashTable{

    int table[100];
    

    public:
    HashTable(){
    for (int i=0 ; i < 50 ; i++){
            table[i] = -63200 ;    
    }
}

void printTable(){
        cout << "Hashtable\n" <<"index   enteries"<<endl;
       for(int i=0 ; i < 50 ; i++){

           if(table[i] != -63200){
               cout << "  "<<i << ".      ";
               cout << table[i] << "  " ;
           }
           else
           {
               cout << "  "<<i << ".     ";
               cout << "-1" << "  " ; 
           }
    
           cout << "\n" ;
       }
    }

static int hashf(int num){
    return (num%50) ;
}

void putele(long int num){
    bool inserted = false ;
    int indx1 , indx2 , indx3 , indx4;
    int i = 0 ; 
    int quadvar ;

    indx1 = HashTable::hashf(num) ;

    if(table[indx1]==-63200){
        table[indx1] = num ; 
        inserted = true ; 
         
    }

    if(!inserted){
        indx2 = HashTable::midsquare(num) ; 

        if(table[indx2]==-63200){
            table[indx2] = num ; 
            inserted = true ;        
        }
    }

    if(!inserted){
        indx3 = HashTable::shifthash((num*num*num)) ; 

        if(table[indx3]==-63200){
            table[indx3] = num ; 
            inserted = true ;     
        }
    }   

    if(!inserted){ 
        indx4 = HashTable::shiftfbhash((num*num*num)) ; 

        if(table[indx4]==-63200){
            table[indx4] = num ; 
            inserted = true ;   
        }
    }
    
    if(!inserted)
        cout << "Element cannot be inserted ." << endl ;
}

static int midsquare(int num){

    int sqr = num*num ;
        int arr[10] ;
        int siz = 0 ;
        int n = sqr ;

        for(int i = 0 ; n!=0 ; i++){
            arr[i] = n%10  ;
            n=n/10 ;
            siz++ ;
        }

        if (siz%2 != 0 ){
            arr[siz] = 0 ;
            siz++ ;
        }

        int middig = arr[siz/2]*10 + arr[(siz/2)-1] ;

        return (middig%50) ;
}

static int shifthash(long int k){

    int arr[25] ;
    int siz = 0 ;

    for(int i = 0 ; k!=0 ; i++){
        arr[i] = k%10  ;
        k=k/10 ;
        siz++ ;
    }
    
    int shiftsum = 0;
    int m = 0 ; 
    if(siz%2!=0){
        shiftsum = arr[m++] ; 
    }


    for(int i = siz-1 ; i>m ; i-=2){

        shiftsum = shiftsum + arr[i]*10+arr[i-1] ; 
    }

    return (shiftsum%50) ;
    
}

static int shiftfbhash(long int k){

    int arr[25] ;
    int siz = 0 ;

    for(int i = 0 ; k!=0 ; i++){
        arr[i] = k%10  ;
        k=k/10 ;
        siz++ ;
    }
    
    int shiftsum = 0;
    int m = 0 ; 
    if(siz%2!=0){
        shiftsum = arr[m++] ; 
    }

    for(int i = siz-1 ; i>m ; i-=2){

        if(i==siz-1 ||  i==siz/2 || i==1)
            shiftsum = shiftsum + arr[i]*10+arr[i-1] ; 
        else 
            shiftsum = shiftsum + arr[i]+arr[i-1]*10 ; 
    }

    return (shiftsum%50) ;  
}
};

int main(){

    HashTable t ;


    t.putele(2) ;
    t.putele(2) ;
    t.putele(102) ;
    
    
    t.putele(20) ;
    t.putele(120) ;
    t.putele(21) ;
    t.putele(320) ;

    t.printTable() ;

}
