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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp1 = l1, *temp2 = l2, *res = NULL, *temp = NULL;
        int sum = 0, carry = 0; 
        
        while(temp1 != NULL && temp2 != NULL) {
            sum = temp1->val + temp2->val + carry ;
            if(sum > 9) {
                carry = (sum/10)%10;
            } else carry = 0 ;
            sum = sum % 10 ;
            
            if(res == NULL) {
                res = new ListNode(sum) ;
                temp = res ;
            } else {
                temp->next = new ListNode(sum) ;
                temp = temp->next ;
            }
            temp1 = temp1->next ; temp2 = temp2->next ;
        }
        
        while(temp1 != NULL) {
            sum = temp1->val + carry ;
            if(sum > 9) {
                carry = (sum/10)%10 ;
            } else carry = 0 ;
            sum = sum%10 ;
            
            if(res == NULL) {
                res = new ListNode(sum) ;
                temp = res ;
            } else {
                temp->next = new ListNode(sum) ;
                temp = temp->next ;
            }
            temp1 = temp1->next ;
        }
        
        while(temp2 != NULL) {
            sum = temp2->val + carry ;
            if(sum > 9) {
                carry = (sum/10)%10 ;
            } else carry = 0 ;
            sum = sum%10 ;
            
            if(res == NULL) {
                res = new ListNode(sum) ;
                temp = res ;
            } else {
                temp->next = new ListNode(sum) ;
                temp = temp->next ;
            }
            
            temp2 = temp2->next ;
        }
        
        if(carry != 0) {
            temp->next = new ListNode(carry) ;
        }
        
        return res ;
        
    }
};  
