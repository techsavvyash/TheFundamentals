#include <iostream>
using namespace std;

template<typename T> class Stack {
    T *arr ;
    int capacity;
    int top;
public:
    Stack(){
        top = -1 ;
        capacity = 256;
        arr = new T[capacity]; 
    }

    Stack(int capacity) {
        this->capacity = capacity;
        top = -1;
        arr = new T[capacity] ;
    }

    void push(T val) {
        if(top < 256) {
            arr[++top] = val;
        } else {
            cout << "Overflow" << endl;
            return; 
        }
    }

    void pop() {
        if(top == -1) {
            cout << "Underflow" << endl;
            return;
        }
        top--;
    }

    T peek() {
        return arr[top] ;
    }

    bool isEmpty() {
        if(top == -1) {
            return true;
        }
        return false;
    }
};

template<typename T> class Queue {
    T *arr;
    int capacity, front, end;
public:
    Queue() {
        capacity = 256;
        front = end = -1;
        arr = new T[capacity] ;    
    }

    Queue(int capacity) {
        this->capacity = capacity ;
        front = end = -1;
        arr = new T[capacity] ;
    }

    void push(T val) {
        if(end != 255){ 
            arr[++end] = val;
        } else {
            cout << "Overflow" << endl;
            return ;
        }

        if(front == -1) ++front;
    }

    void pop() {
        if(front == -1) {
            cout << "Underflow" << endl;
            return;
        }
        if(front == end) {
            front = end = -1;
            return ;
        }

        ++front ;
    }

    bool isEmpty() {
        if(front == -1 && end == -1) {
            return true;
        }
        return false;
    }

    T peek() {
        return arr[front] ;
    }
};


template<typename T> class ListNode {
public:
    T val;
    ListNode* next;

    ListNode() {
        next = NULL;
    }

    ListNode(T val) {
        this->val = val;
        next = NULL;
    }
};

template<typename T> class List {    
public:
    ListNode<T> *head;
    ListNode<T> *tail;
    int listSize;

    List() {
        head = tail = NULL;
        listSize = 0;
    } 

    void add(T val) {
        if(head == NULL) {
            head = new ListNode<T>(val) ;
            tail = head;
            listSize++ ;
            return;
        }

        tail->next = new ListNode<T>(val) ;
        tail = tail->next ;
        listSize++ ;
        return;
    }

    void printList() {
        ListNode<T> *temp = head ;
        while(temp != tail) {
            cout << temp->val << ", ";
            temp = temp->next ;
        }
        cout << temp->val<<endl;
    }
};

template<typename T> class Graph {
    int vertices; //number of vertices
    T *vertexMap ; //stores the vertices
    List<T> **adj; //an array that stores the linked list of adjacent vertices (adjacencyList) of each vertex

public:
    Graph(int vertices) {
        this->vertices = vertices ; 
        this->vertexMap = new T[this->vertices] ;
        this->adj = new List<T>*[vertices];

        for(int i=0;i<vertices;i++) {
            adj[i] = NULL;
        }

        addVertex();
    }

    int findVertexMapping(T vertex) {
        for(int i = 0;i < vertices;i++) {
            if(vertexMap[i] == vertex) {
                return i;
            }
        }
        return -1 ;
    }
    
    void addVertex() {
        for(int i=0;i<vertices;i++) {
            cout << "Enter vertex number " << i+1 << ": ";
            T temp;
            cin >> temp;
            vertexMap[i] = temp ;
        }
    }

    void addEdge(T src, T dest, bool twoWay = false) {
        int i = findVertexMapping(src);
        int j = findVertexMapping(dest);

        if(i != -1 && j != -1) {
            if(adj[i] == NULL) {
                adj[i] = new List<T>();
            }
            if(adj[j] == NULL) {
                adj[j] = new List<T>();
            }
            adj[i]->add(dest);
            if(twoWay) {
                adj[j]->add(src) ;
            }
        } else {
            cout << "Invalid src or dest" << endl;
        }

        return ;
    }

    void printGraph() {
        for(int i=0;i<vertices;i++) {
            cout << vertexMap[i] << ": ";
            adj[i]->printList() ;
        }
    }


    void BFS(T src) {
        //bfs is queue based
        bool *visited = new bool[vertices];
        for(int i = 0;i<vertices;i++) {
            visited[i] = false;
        }
        int i = findVertexMapping(src);
        Queue<int> q(this->vertices) ;
        q.push(i) ;

        while(!q.isEmpty()) {
            int vertex = q.peek();
            cout << vertexMap[vertex] << " ";
            q.pop();
            //i = findVertexMapping(vertex) ;
            visited[vertex] = true ;
            ListNode<T> *temp = adj[vertex]->head;
            while(temp!=NULL) {
                int j = findVertexMapping(temp->val) ;
                if(!visited[j]) {
                    q.push(j);
                    visited[j] = true ;
                }
                temp = temp->next ;
            }
        }
        cout << endl;
    }

    void DFS(T src) {
        //dfs is stack based
        bool *visited = new bool[vertices];
        for(int i = 0;i<vertices;i++) {
            visited[i] = false;
        }
        int i = findVertexMapping(src);
        Stack<int> q(this->vertices) ;
        q.push(i) ;

        while(!q.isEmpty()) {
            int vertex = q.peek();
            cout << vertexMap[vertex] << " ";
            q.pop();
            //i = findVertexMapping(vertex) ;
            visited[vertex] = true ;
            ListNode<T> *temp = adj[vertex]->head;
            while(temp!=NULL) {
                int j = findVertexMapping(temp->val) ;
                if(!visited[j]) {
                    q.push(j);
                    visited[j] = true ;
                }
                temp = temp->next ;
            }
        }
        cout << endl;
    }
};

int main() {
    Graph<char > g(4);
    g.addEdge('A', 'B');
    g.addEdge('A', 'C');
    g.addEdge('A', 'D');
    g.addEdge('B', 'C');
    g.addEdge('C', 'D');
    g.addEdge('D', 'A');
    g.printGraph() ;
    g.BFS('A');
    g.DFS('A');

    return 0;
}