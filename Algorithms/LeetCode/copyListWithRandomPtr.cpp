/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *temp = head, *res = NULL, *t = NULL ;
        map<Node*, Node*> table ; //original, copied
        while(temp != NULL) {
            if(res == NULL) {
                res = new Node(temp->val) ;
                t = res ;
            } else {
                t->next = new Node(temp->val) ;
                t = t->next ;
            }
            table[temp] = t ;
            temp = temp->next ;
        }
        
        
        temp = head ; t = res ;
        
        while(temp != NULL) {
            if(temp->random) {
                t->random = table[temp->random] ;
            }
            
            temp = temp->next ;
            t = t->next ;
        }
        
        return res ;
    }
};
