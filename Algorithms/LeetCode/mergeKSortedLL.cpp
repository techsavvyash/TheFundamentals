/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int> > pq ;
        int n = lists.size() ;
        
        for(int i = 0; i < n; i++) {
            ListNode* temp = lists[i] ;
            while(temp != NULL) {
                pq.push(temp->val) ;
                temp = temp->next ;
            }
        }
        ListNode *temp = new ListNode(pq.top());
        ListNode *res = temp ;
        pq.pop() ;
        cout << "All happy till here!!" << endl;
        int i = 0;
        while(!pq.empty()) {
            cout << "i: " << i++ << endl;
            cout << "temp->val: " << res->val << endl;
            temp->next = new ListNode(pq.top());
            temp = temp->next ;
            pq.pop() ;
        }
        cout << "res->val: " << res->val << endl ;
        return res ;
         
    
    }
};
/*class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode*t, *q;
        q=nullptr;
        priority_queue<int>pq;
        for(auto c:lists){
            t=c;
            while(t){
                pq.push(t->val);
                t=t->next;
            }
        }
        while(!pq.empty()){
            ListNode*temp=new ListNode(pq.top());
            temp->next=q;
            q=temp;
            pq.pop();
        }
        return q;
    }
};*/
