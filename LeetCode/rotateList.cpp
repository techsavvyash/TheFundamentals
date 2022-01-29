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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == NULL || head->next == NULL) {
            return head ;
        }
        
    
        ListNode* temp = head ; int len = 0 ;
        while(temp->next->next != NULL) {
            temp = temp->next ;
            len++ ;
        }
        len+=2 ;
        
        
        if(k%len == 0) {
            return head ;
        }
        temp->next->next = head ;
        for(int i = 0 ; i <= (len - (k%len)) ;i++) {
            temp = temp->next ;
        }
        head = temp->next ;
        temp->next = NULL ;
        return head ;
    }
};
