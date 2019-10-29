/*
Final Code of graph bfs dfs using adjacency List
*/

#include <iostream>
#include <vector>
using namespace std;

class Node{
    int vertexnum ; 
    Node *nextedgeconn , *nextnode ; 
    public:
    Node(){
        this->vertexnum = -1 ;
        this->nextnode = NULL ;
        this->nextedgeconn = NULL ;  
    }
    Node(int vertex){
        this->vertexnum = vertex ; 
        this->nextnode = NULL ; 
        this->nextedgeconn = NULL ; 
    }
    friend class Graph ; 
};
class Graph {
private: 
       Node *root; 
      int numVertices;
public:
    Graph(int numVertices) {
        this->numVertices = numVertices ; 
        this->root = new Node(0) ;
        Node *temp = root ; 
        for(int i = 1 ; i < numVertices ; i++){
            temp->nextnode = new Node(i);
            temp = temp->nextnode ; 
        }
    }
    
    void addEdge(int i, int j) {
        Node *temp = this->root ; 
        while(temp->vertexnum != i){
        temp = temp->nextnode ; 
        }

        while(temp->nextedgeconn !=NULL){
            temp = temp->nextedgeconn ; 
        }

        temp->nextedgeconn = new Node(j) ;
    }
    
    void removeEdge(int i, int j) {
        Node *temp = this->root ; 

        while(temp->vertexnum != i){
            temp = temp->nextnode ; 
        }

        while(temp->nextedgeconn !=NULL){
            if(temp->nextedgeconn->vertexnum == j){
                Node *temp2 = temp->nextedgeconn ;
                // add exception for last node here
                temp->nextedgeconn = temp2->nextedgeconn ; 

                delete temp2 ;
            } 
            else {
                temp = temp->nextedgeconn ; 
            }
            
        }
    }
    
    bool isEdge(int i, int j) {
        Node *temp = this->root ; 

        while(temp->vertexnum != i){
            temp = temp->nextnode ; 
        }

        while(temp->nextedgeconn !=NULL){
            if(temp->nextedgeconn->vertexnum == j){
                return true ; 
            } 
            else{
                temp = temp->nextedgeconn ; 
            }
        }
        return false ; 
    }

    void printAdjlist() {
        cout << "Adjacency Matrix of Graph\n" << endl ; 
        Node *temp1 , *temp2 ; 

        temp1 = this->root ; 

        cout << "Adjacency List of Matrix is : " << endl ; 
        while(temp1!=NULL){
            cout << temp1->vertexnum << " " ; 
            temp2 = temp1->nextedgeconn ; 

            while(temp2!=NULL){
                cout << temp2->vertexnum << " " ; 
                temp2 = temp2->nextedgeconn ; 
            }

            cout << endl ; 

            temp1 = temp1->nextnode ;             
        }
        cout << "\n"<< endl ; 

    }


    static void bfs (Graph g, int s){

        bool visited[g.numVertices];

        for (int i = 0 ; i < g.numVertices ; i++){
            visited[i] = false ; 
        }

        vector<int> queue ; 

        visited[s] = true ; 
        queue.push_back(s) ; 

        while(!queue.empty()){
            s = queue.front() ;  // Just getting or retriving the first element of queue

            cout << s << " " ;

            queue.erase(queue.begin(),queue.begin()+1) ; // Removing the First element of the queue 

            Node *temp = g.root ; 

            while (temp!=NULL){
                if(temp->vertexnum == s)
                    break  ;
                else 
                    temp = temp->nextnode ;
            }

            Node *temp2 = temp->nextedgeconn ;

            while(temp2!=NULL){
                if(!visited[temp2->vertexnum]){
                    visited[temp2->vertexnum] = true ;
                    queue.push_back(temp2->vertexnum) ;
                }

                temp2 = temp2->nextedgeconn ; 
            } 
        }
    }//}

    static void dfs(Graph g , int s){

        bool visited[g.numVertices] ; 

        for(int i = 0 ; i < g.numVertices ; i++){
            visited[i] = false ; 
        }
        dfsrec(s,visited ,g) ;
    }

    static void dfsrec(int s , bool visited[] , Graph g){

        visited[s] = true ; 

        cout << s <<" " ;

        Node *temp = g.root ; 

        while (temp!=NULL){
            if(temp->vertexnum == s)
                break  ;
            else 
                temp = temp->nextnode ;
        }

        Node *temp2 = temp->nextedgeconn ;

        while(temp2!=NULL){

            if(!visited[temp2->vertexnum]){
                dfsrec(temp2->vertexnum , visited , g) ;
            }
            
            else 
                temp2 =  temp2->nextedgeconn  ;
        }  
    }  
};


int main(){
    int numVertices ;
    cout << "Enter the Number of Vertices of Graph :";
    cin >> numVertices ; 
     
    Graph g(numVertices);
    int choice  ; 
    bool exit = false ; 

    while(!exit){
        cout << "\n1. Add Edge Btw two Vertices." << endl ;
        cout << "2. Remove Edge Btw two Vertices." << endl ;
        cout << "3. Check if there is an edge btw vertices or not" << endl ;
        cout << "4. Print Adjacency List of graph"<< endl ;
        cout << "5. To get BFS , DFS Traversals of graph"<< endl ;
        cout << "6. exit"<< endl ;
        cout << "Your Choice :";
        cin >> choice ;

        switch (choice)
        {
            case 1:
                {   char ext='n' ; 
                    do
                    {
                        int vertex1 , vertex2 ; 

                        cout << "Enter Number of Two vertices. (must be separated by spaces and must be less than "<<numVertices<<endl ; 
                        cin >> vertex1 >> vertex2 ;
                        g.addEdge(vertex1,vertex2);

                        cout << "Enter Another Edge. (y/n)    :" ;
                        cin >> ext ; 
                    
                    } while (ext!='n');
                }
                break;
            case 2:
                {
                        int vertex1 , vertex2 ; 

                        cout << "Enter Number of Two vertices whose edge to delete \n (must be separated by spaces and must be less than "<<numVertices<<endl ; 
                        cin >> vertex1 >> vertex2 ;
                        g.removeEdge(vertex1,vertex2);
                    
                }
                    break;
            
            case 3:
                 {
                        int vertex1 , vertex2 ; 

                        cout << "Enter Number of Two vertices to check \n (must be separated by spaces and must be less than "<<numVertices<<endl ; 
                        cin >> vertex1 >> vertex2 ;
                        
                        if(g.isEdge(vertex1 , vertex2)){
                            cout << "Edge is present between these Vertices .\n" << endl ; 
                        }
                        else{
                            cout << "Edge is not present between these Vertices .\n" << endl ; 
                        }
                    
                }
                    break;

            case 4:
                g.printAdjlist() ; 
                break  ;
            case 5 :
                int strtpt ;
                cout << "Enter the starting point :" << endl ;
                cin >> strtpt ;
                cout << "BFS :" << endl ; 
                Graph::bfs(g , strtpt) ;
                cout << endl ;
                cout << "DFS :" << endl ; 
                Graph::dfs(g,strtpt) ;
                break  ; 
            case 6:
                exit = true ; 
                break ; 
            default:
                break;
        }
    }

}