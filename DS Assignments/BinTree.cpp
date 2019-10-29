
#include<iostream>

using namespace std  ;

class bintree ;
class Node{
    private:
        double data ;
        Node *left , *right ;

    public:
        Node(){
        this->data = -1 ;
        this->left = NULL ;
        this->right = NULL ;
        }

        Node(double element){
        this->data = element ;
        this->left = NULL ;
        this->right = NULL ;
        }

    friend class Bintree ;

    static bool isLeaf(Node *temp){

        if (temp->left == NULL && temp->right == NULL)
            return true ;
        else return false ;

    }
};



class Bintree{

    Node *root  ;
    int noOfNodes ;

    public:
        Bintree(){
          this->root = NULL  ;
          noOfNodes = 0 ;
        }

    static void insert(Bintree &bt , double key)  ;

    int getNoOfNodes(){
        return this->noOfNodes ;
    }

    static void order(Bintree &bt , int opcode) ;
    static void order(Node *node , int opcode) ;

    static Node* bsearch(Bintree &bt , double key) ;
    static Node* bsearch(Node *node , double key) ;

    static bool deleteNode(Bintree &bt , double key) ;

    static Node* getParent(Bintree &bt , double key) ;
    static Node* getParent(double key ,Node *node) ;

};

void Bintree::insert(Bintree &bt , double key){

    Node *newnode = new Node(key) ;
    bool inserted = false ;

    if(bt.root == NULL){
        bt.root = newnode ;
    }

    else {

        Node *temp = bt.root ;
        while(1){
            if (key <= temp->data){

                    if(temp->left == NULL){
                        temp->left = newnode ;
                        break ;
                    }
                    else {
                        temp = temp->left ;
                    }

            }
            else if (key > temp->data){
                if(temp->right == NULL){
                    temp->right = newnode ;
                    break ;
                }
                else{
                    temp = temp->right ;
                }
        }
      }
    }

    bt.noOfNodes++ ;
}



void Bintree::order(Bintree &bt , int opcode = 1 ){

    if (bt.root==NULL){
        cout << "Tree Empty" ;

    }
    else{
        cout << "================================================================================================\n\n" ;
        Bintree::order(bt.root , opcode) ;
        cout << "\n\n================================================================================================\n" ;
    }
}

void Bintree::order(Node *node , int opcode = 1){

    if (node != NULL){

        switch (opcode)
        {
            case 1:

                Bintree::order(node->left , opcode) ;
                cout << " " << node->data << " " ;
                Bintree::order(node->right, opcode) ;

                break;

            case 2:

                cout << " " << node->data << " " ;
                Bintree::order(node->left , opcode) ;
                Bintree::order(node->right, opcode) ;

                break;

            case 3:

                Bintree::order(node->left, opcode) ;
                Bintree::order(node->right, opcode) ;
                cout << " " << node->data << " " ;

                break;

            default:
                break;
        }
    }
}

Node* Bintree::bsearch(Bintree &bt , double key){
    if (bt.root == NULL)
        return NULL ;
    else {
        return Bintree::bsearch(bt.root , key) ;
    }
}

Node* Bintree::bsearch(Node *node , double key){

    if (node == NULL){
        return NULL ;
    }
    else if (key > node->data)
        return Bintree::bsearch(node->right , key) ;
    else if (key < node->data)
        return Bintree::bsearch(node->left , key) ;
    else if (key == node->data){
        return node ;
    }
}

Node* Bintree::getParent(Bintree &bt , double key ){

    if (bt.root == NULL){
        return NULL ;
    }
    else{
        return Bintree::getParent(key ,bt.root) ;
    }


}

Node* Bintree::getParent(double key , Node* node){

    if(node != NULL || !(node->left == NULL && node->right == NULL) ){

        if(node->left->data == key || node->right->data == key){
            return node ;
            }

        else if (key > node->data ){
           return Bintree::getParent(key , node->right ) ;
        }

        else if (key < node->data){
            return Bintree::getParent(key , node->left) ;
        }

        else if (node == NULL){
            return NULL ;
        }

    }



}


bool Bintree::deleteNode(Bintree &bt , double key){
{

        Node *temp = Bintree::bsearch(bt.root , key) ;
        Node *parent = Bintree::getParent(bt , key);

        if (temp->left == NULL){        // Temp has only Right Child
        cout << "right only trigered" << endl ; 
            if(temp->data <= parent->data) {
                parent->left = temp->right ;
            }

            else{
                parent->right = temp->right ;
            }
            delete temp ;
        }

        else if (temp->right == NULL)         // Temp has only left child
        {   cout << "left only trigered" << endl ; 
            if(temp->data <= parent->data){
                parent->left = temp->left ;
            }

            else{
                parent->right = temp->left ;
            }
            delete temp ;

        }

        else if (Node::isLeaf(temp)){    // Temp has no child 
            cout << "no trigered" << endl ; 
            if(temp->data <= parent->data){
                parent->left = NULL ;
            }

            else{
                parent->right = NULL ;
            }
            delete temp ;
        }

        else{              // Temp has both Childs
            
            Node *repnode = temp->right ;              // Node to replace
            Node *repnodeP = temp->right ; //= temp->right ;             // Parent of Node to Replace

            while(repnode->left != NULL){
            	repnodeP = repnode ; 

                repnode = repnode->left ;
            }

            //repnodeP = Bintree::getParent(bt , repnode->data);

            if(repnodeP == /*temp*/ repnode){
                temp->right = repnode->right ;
            }
            else
              repnodeP->left = repnode->right ;

            temp->data = repnode->data ;


            delete repnode ;
        }

        return true ;
    }
}



int main()
{
    Bintree bt1 ;

    int choice ;
    bool exit = false ;

    do{
        cout <<"\n\nBST Operations : " << endl ;
        cout << "1. ADD/Insert Element" << endl ;
        cout << "2. Display Element" << endl ;
        cout << "3. Search Element" << endl ;
        cout << "4. Delete Element" << endl ;
        cout << "5. exit " << endl ;
        cout <<"Your Choice : " ;
        cin >> choice ;

        switch (choice)
        {
            case 1:
                {
                    /*9char another = 'n' ;
                    double data ;
                    do{
                    cout << "Enter data to enter : " ;
                    cin >> data ;

                    Bintree::insert(bt1 , data) ;

                    cout << "Enter Another term y/n : " << endl;
                    cin >> another ;
                    }while(another != 'n') ;*/

                    Bintree::insert(bt1 , 25) ;
                    Bintree::insert(bt1 , 10) ;
                    Bintree::insert(bt1 , 2) ;
                    Bintree::insert(bt1 , 1) ;
                    Bintree::insert(bt1 , 30) ;
                    Bintree::insert(bt1 , 26) ;
                    Bintree::insert(bt1 , 3) ;
                    Bintree::insert(bt1 , 18) ;
                }
                break;

            case 2:
                cout << "Inorder of Tree : \n" ;
                Bintree::order(bt1 , 1) ;
                cout << endl ;

                cout << "Preorder of Tree : \n" ;
                Bintree::order(bt1 , 2 ) ;
                cout << endl ;

                cout << "Postorder of Tree : \n" ;
                Bintree::order(bt1 , 3 ) ;
                cout << endl ;
                break ;

            case 3:
                cout << "Enter the Element to search : ";
                double ele ;
                cin >> ele ;

                //Node *term = Bintree::bsearch(bt1 , ele) ;

                if (Bintree::bsearch(bt1 , ele) != NULL)
                    cout << "Element found in Tree : " << endl;
                else
                    cout << "Element not found in tree\n";
                break ;

            case 4:
                 cout << "Enter the Element to delete : ";
                 double delTerm ;
                 cin >> delTerm ;

                if(Bintree::bsearch(bt1 , delTerm)){
                 bool isDeleted  ;
                 isDeleted = Bintree::deleteNode(bt1 , delTerm) ;

                 if(isDeleted)
                    cout << "Element delete successfull" << endl ;

                 else
                    cout << "Element deletion failed " << endl ;
                }
                else
                    cout << "element Not found . deletion not possible"<<endl ;
                break ;

            case 5:
                exit = true ;
                break ;

            default:
                break;
        }
    }while(!exit) ;

    return 0;
}

