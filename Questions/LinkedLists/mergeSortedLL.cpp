/*Problem Link: https://leetcode.com/problems/merge-two-sorted-lists/submissions/*/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL) { return NULL ;}
        if(l1 == NULL && l2 != NULL) { return l2 ; }
        if(l1 != NULL && l2 == NULL) { return l1; }
        ListNode* temp1 = l1 ;
        ListNode* temp2 = l2 ;
        ListNode* newList = NULL ;
        if(temp1->val > temp2->val) {
            newList = new ListNode(temp2->val);
            temp2 = temp2->next ;
        } else {
            newList = new ListNode(temp1->val);
            temp1 = temp1->next ;
        }
        
        ListNode* temp3 = newList ;
        
        while(temp1 != NULL && temp2 != NULL) {
            if(temp1->val < temp2->val) {
                temp3->next = new ListNode(temp1->val);
                temp1 = temp1->next ;
            } else {
                temp3->next = new ListNode(temp2->val) ;
                temp2 = temp2->next ;
            }
            temp3 = temp3->next ;
        }
        
        while(temp1 != NULL) {
            temp3->next = new ListNode(temp1->val);
            temp3 = temp3->next ;
            temp1 = temp1->next ;
        }
        
        while(temp2 != NULL) {
            temp3->next = new ListNode(temp2->val);
            temp3 = temp3->next ;
            temp2 = temp2->next ;
        }
        
        return newList ;
        
        
    }
};