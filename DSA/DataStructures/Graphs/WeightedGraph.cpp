#include <iostream>
#include <climits>
using namespace std;

class Pair {
    public:
    int weight, vertex;
    Pair(int weight, int vertex) {
        this->weight = weight ;
        this->vertex = vertex ;
    }
};

class MinHeap {
    int *arr, size, capacity;
    int *vertices ;

    void swap(int idx1, int idx2) {
        arr[idx1] = arr[idx1] + arr[idx2] ;
        arr[idx2] = arr[idx1] - arr[idx2] ;
        arr[idx1] = arr[idx1] - arr[idx2] ;
        vertices[idx1] = vertices[idx1] + vertices[idx2] ;
        vertices[idx2] = vertices[idx1] - vertices[idx2] ;
        vertices[idx1] = vertices[idx1] - vertices[idx2] ;
    }

    void heapify(int idx) {
        int minIdx = idx ;
        int leftChild = idx*2 ;
        int rightChild = idx*2 + 1 ;

        if(leftChild <=size && arr[minIdx] > arr[leftChild]) {
            minIdx = leftChild ;
        }

        if(rightChild <= size && arr[minIdx] > arr[rightChild]) {
            minIdx = rightChild ;
        }

        if(minIdx != idx) {
            swap(minIdx, idx) ;
            heapify(minIdx) ;
        }
    }


public:
    MinHeap() {
        arr = new int[capacity = 16] ;
        vertices = new int[capacity] ;
        size = 0;
        arr[0] = -1 ; 
    }

    MinHeap(int capacity) {
        arr = new int[this->capacity = capacity] ;
        vertices = new int[capacity] ;
        size = 0;
        arr[0] = -1 ;
    }

    void push(int weight, int vertex) {
        if(size == capacity) {
            int *newArr = new int[capacity = 2*capacity];
            int *newVertices  = new int[capacity] ;
            for(int i=0;i<= size;i++) {
                newArr[i] = arr[i] ;
                newVertices[i] = vertices[i] ;
            }
            arr = newArr ;
            vertices = newVertices ;
        }

        arr[++size] = weight ;
        vertices[size] = vertex ;
        int child = size ;
        int parent = child / 2 ;

        while(child > 1 && arr[parent] > arr[child]) {
            swap(parent, child) ;
            child = parent ;
            parent = parent / 2 ; 
        }
    }

    void pop() {
        swap(1, size);
        size-- ;
        heapify(1) ;
    }

    Pair top() {
        return Pair(arr[1], vertices[1]);
    }

    bool isEmpty() {
        return size == 0 ;
    }

};


class WeighListNode {
    int vertex;
    int weight;
    WeighListNode* next;

public:
    WeighListNode() {
        next = NULL;
    }

    WeighListNode(int vertex, int weight) {
        this->vertex = vertex;
        this->weight = weight;
        next = NULL;
    }

    friend class WeightedList;
    friend class WeightedGraph ;
};

class WeightedList {
    WeighListNode *tail;

public:
    WeighListNode *head;

    WeightedList() {
        head = tail = NULL;
    }

    void push(int vertex, int val) {
        if(head == NULL) {
            head = new WeighListNode(vertex, val);
            tail = head;
            return;
        }

        tail->next = new WeighListNode(vertex, val);
        tail = tail->next ;
    }

    bool isEmpty() {
        if(head == NULL) {
            return true;
        }
        return false;
    }

    void printList() {
        WeighListNode* temp = head;
        while(temp!= tail && temp != NULL) {
            cout << "[vertex: " << temp->vertex << " weight: " << temp->weight << "], " ;
            temp = temp->next ;
        }
        cout << "[vertex: " << temp->vertex << " weight: " << temp->weight << "]\n";
    }

    WeighListNode* getHead() {
        return head ;
    }

    

};

class WeightedGraph {
    int vertices;
    WeightedList **adj; //adjacency List representing array of WeightedList pointes

public:
    WeightedGraph(int vertices) {
        this->vertices = vertices ;
        adj = new WeightedList*[vertices+1] ;
    }

    void addEdge(int src, int dest, int weight, bool twoWay = true) {
        cout << "inside addEdge" << endl;
        if(adj[src] == NULL) {
            adj[src] = new WeightedList();
        }
        
        adj[src]->push(dest, weight) ;

        if(twoWay) {
            if(adj[dest] == NULL) {
            adj[dest] = new WeightedList();
        }
            adj[dest]->push(src, weight);
        }
    }

    void printAdj() {
        for(int i = 1;i<vertices;i++) {
            cout << i <<": " ;
            adj[i]->printList();
        }
    }

    void dijkstra(int src) {
        bool visited[vertices + 1][vertices + 1] = {false} ;
        int *distances = new int[vertices + 1] ;

        for(int i = 1;i<=vertices;i++) {
            //initialising distances
            if(i == src) {
                distances[i] = 0;
                continue ;
            }
            distances[i] = INT_MAX ;
        }

        MinHeap dijkPQ;
        WeighListNode *temp = adj[src]->getHead() ;
        
        // while(temp != NULL) {
        //     dijkPQ.push(temp->weight, temp->vertex) ;
        //     visited[src][temp->vertex] = true ;
        // }
        dijkPQ.push(0, src);
        //for(int i = 1;i<=vertices; i++) {
        //    if(adj[i] != NULL) {    
        //        WeighListNode *temp = adj[i]->getHead();
        //        while(temp != NULL) {
        //            distances[temp->vertex] = distances[temp->vertex] >  (distances[i] + temp->weight) ? (distances[i] + temp->weight) : distances[temp->vertex] ;
        //        }
        //    }
        //}
        
        while(!dijkPQ.isEmpty()) {
            Pair first = dijkPQ.top() ;
            dijkPQ.pop();
            int parentDist = first.weight ;
            int parent = first.vertex ;
            distances[first.vertex] = (distances[first.vertex] > distances[src] + first.weight) ? distances[src] + first.weight : distances[first.vertex] ;
            src = first.vertex ;
            temp = adj[parent]->getHead() ;

            while(temp != NULL) {
                int edgeDist = temp->weight ;   
                if(distances[temp->vertex] > parentDist + edgeDist) {
                    distances[temp->vertex] = parentDist + edgeDist ;
                    dijkPQ.push(distances[temp->vertex], temp->vertex); 
                }
                // if(!visited[src][temp->vertex]) {
                //     dijkPQ.push(temp->weight, temp->vertex);
                //     visited[src][temp->vertex] = true ;
                // }
                temp = temp->next ;
            } 
        }

        //printing the distances

        for(int i=1;i<=vertices;i++) {
            cout << i << ": " << distances[i] << endl;
        }
    }

    void bellman(int src) {
        //DP based algo
        int *distances = new int[vertices + 1] ;
        //setting initial values
        for(int i=1;i<=vertices;i++) {
            if(i == src) {
                distances[i] = 0;
                continue ;
            }

            distances[i] = INT_MAX ;
        }

        //relaxing each edge V-1 times

        for(int i=1;i<vertices;i++) {
            for(int i=1;i<=vertices;i++) {
                if(adj[i]!= NULL) {
                    WeighListNode *temp = adj[i]->getHead() ;
                    while(temp != NULL) {
                        if(distances[temp->vertex] > distances[i] + temp->weight) {
                            distances[temp->vertex] = distances[i] + temp->weight ;
                        }
                        temp = temp->next ;
                    }
                }
            }
        }

        //checking for negative weight cycles

        for(int i=1;i<=vertices;i++) {
            if(adj[i] != NULL) {
                WeighListNode *temp = adj[i]->getHead() ;
                while(temp != NULL) {

                    if(distances[temp->vertex] > distances[i] + temp->weight) {
                        cout << "Negative Weight Cycle Present!" << endl;
                        exit(0) ;
                    }
                    temp = temp->next ;
                }
            }
        }

        //printing all the weights

        for(int i=1; i<=vertices;i++) {
            cout << i << ": " << distances[i] << endl;
        }
    }

    void prims(int src) {
        bool *visited = new bool[vertices+1] ;
        for(int i=1;i<=vertices;i++) {
            if(adj[i] != NULL) {
                visited[i] = false;
            }
        }
        visited[src] = true;
        int mstWeight = 0;
        int activeVertex = src;
        MinHeap primPQ;
        WeightedGraph MST(vertices);
        WeighListNode *temp = adj[src]->getHead();
        while(temp != NULL) {
            primPQ.push(temp->weight, temp->vertex);
            temp = temp->next;
        }
        
        while(!primPQ.isEmpty()) {
            Pair currentEdge = primPQ.top();
            if(!visited[currentEdge.vertex]) {
                mstWeight += currentEdge.weight;
                MST.addEdge(activeVertex, currentEdge.vertex, currentEdge.weight) ;
                activeVertex = currentEdge.vertex ;
                visited[activeVertex] = true;
                temp = adj[activeVertex]->getHead();
                while(temp != NULL) {
                    if(!visited[temp->vertex]){
                        primPQ.push(temp->weight, temp->vertex);
                    }
                    
                    temp = temp->next ;
                }
            }
            primPQ.pop();

            
        }

        cout << "MST Weight: " << mstWeight << endl;
        cout << "MST is: " << endl;
        MST.printAdj() ;
    }

};


int main() {
  
    WeightedGraph G(4);
    G.addEdge(1, 2, 3); 
    G.addEdge(1, 3, 2);
    G.addEdge(1, 4, 9);
    G.addEdge(2, 3, 5);
    G.addEdge(3, 4, 6);
    G.addEdge(2, 4, 2);
    cout << "Adjacency List: " << endl ; G.printAdj() ;
    cout << "Dijkstra: " << endl ; G.dijkstra(1) ;
    cout << "Bellman: " << endl ; G.bellman(1) ;
    G.prims(1) ;

    WeightedGraph P(3);
    P.addEdge(1, 2, 2);
    P.addEdge(2, 3, 4);
    P.addEdge(3, 1, 1);
    P.prims(1);

    return 0;
}