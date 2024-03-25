/*Problem Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list*/

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp = head;
        if(head == NULL){
            return head ;
        }
        bool flag = false ;
        while(temp != NULL && temp->next != NULL ) { 
            if(temp->val == temp->next->val) {
                temp->next = temp->next->next ;
                flag = true ;
            }
            temp = temp->next ;
        }
        if(flag) {
            return deleteDuplicates(head);
            
        }
        
        return head ;
    }
};