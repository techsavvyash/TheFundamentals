/*Problem Link: https://leetcode.com/problems/remove-linked-list-elements/submissions/*/

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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) {
            return head ;
        }
        
        ListNode* temp = head->next ;
        ListNode* prev = head ;
        
        while(temp) {
            if(temp->val == val) {
                prev->next = temp->next;
            } else {
                prev = prev->next ;
            }
            temp = temp->next ;
        }
        
        if(head->val == val) head = head->next ;
        
        return head ;
    }
}; 