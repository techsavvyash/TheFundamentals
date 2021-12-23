/*Problem Link: https://leetcode.com/problems/reverse-linked-list*/

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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* prev = head ;
        ListNode* current = head->next ;
        ListNode* temp = current->next ;
        prev->next = NULL ;
        while(temp != NULL) {
            current->next = prev ;
            prev = current ;
            current = temp ;
            temp = temp->next ;
        }
        current->next = prev;
        
        return current ;
        
    }
};