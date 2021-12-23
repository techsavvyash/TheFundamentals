#include <iostream>
using namespace std;

template <typename T> class BSTNode {
public:
    T data;
    BSTNode<T> *leftChild;
    BSTNode<T> *rightChild;

    
    BSTNode(T data) {
        this->data = data;
        leftChild = rightChild = NULL;
    }

    void insert(T key) {
        
        if(this->data > key) {
            if(this->leftChild) this->leftChild->insert(key);
            else this->leftChild = new BSTNode<T>(key);
            return;
        } else if(this->data < key) {
            if(this->rightChild) this->rightChild->insert(key);
            else this->rightChild = new BSTNode<T>(key);
            return;
        } else {
            cout << "Key Already Present!" << endl;
            return;
        }
    }

    void inorder() {
        if(this->leftChild != NULL) {
            this->leftChild->inorder();
        }
        cout << this->data << " " ;
        if(this->rightChild != NULL) {
            this->rightChild->inorder() ;
        }   
    }

    void preorder() {
        cout << this->data << " ";
        if(this->leftChild) this->leftChild->preorder() ; 
        if(this->rightChild) this->rightChild->preorder() ;
    }

    void postorder() {
        if(this->leftChild) this->leftChild->preorder() ; 
        if(this->rightChild) this->rightChild->preorder() ;
        cout << this->data << " ";
    }

    BSTNode<T>* search(T data) {
        if(this->data == data) {
            return this ;
        } else if(this->data > data && this->leftChild != NULL) {
            return this->leftChild->search(data) ;
        } else if (this->data < data && this->rightChild != NULL) {
            return this->rightChild->search(data) ;
        } 

        return NULL;
    }

    BSTNode<T>* findParent(BSTNode<T> *node) {
        if(this->leftChild == node || this->rightChild == node) {
            return this;
        } else if(this->data > node->data) {
            return this->leftChild->findParent(node) ;
        }

        return this->rightChild->findParent(node);
    }    
};

template <typename T> class BST {
    BSTNode<T> *root;
public:
    BST() {
        root = NULL;
    }

    void insert(T data) {
        if(root == NULL) {
            root = new BSTNode<T>(data);
            return;
        }
        root->insert(data);
    }

    BSTNode<T>* search(T data) {
        return root->search(data);
    }

    BSTNode<T>* findParent(BSTNode<T> *node) {
        return root->findParent(node) ;
    }

    void deleteNode(T key) {
        BSTNode<T> *node = root->search(key);
        if(node == NULL) {
            cout << "Key Not Present! " << endl;
            return;
        } 
        BSTNode<T> *parent = findParent(node);
        if(node->leftChild == NULL) {
            if(parent->data > node->data) {
                parent->leftChild = node->rightChild ;
            } else {
                parent->rightChild = node->rightChild ;
            }
            delete node ;
        } else {
            BSTNode<T> *rightMost = node;
            BSTNode<T> *parentOfRightMost = parent;

            while(rightMost->rightChild != NULL) {
                parent = rightMost;
                rightMost = rightMost->rightChild ;
            }

            node->data = rightMost->data ;

            if(parentOfRightMost->rightChild == rightMost) parentOfRightMost->rightChild = rightMost->leftChild;
            else parentOfRightMost->leftChild = rightMost->leftChild ; //Special case when node itself is the rightmost node
        }
    }

    void inorder() {
        root->inorder() ;
    }

    void preorder() {
        root->preorder() ;
    }
    
    void postorder() {
        root->postorder() ;
    }
};


int main() {

    BST<int> B;

    B.insert(3);
    B.insert(1);
    B.insert(2);
    B.insert(4);

    B.inorder() ; cout << endl;
    B.preorder(); cout << endl;
    B.postorder() ; cout << endl;
    BSTNode<int> *res = B.search(4);
    cout << (res == NULL) << endl;
    res = B.search(4) ;
    cout << res->data << endl;

    B.deleteNode(1);
    res = B.search(1);
    cout << (res == NULL) << endl;
    B.inorder(); cout << endl;

    return 0;
} 