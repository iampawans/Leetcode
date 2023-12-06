// https://leetcode.com/problems/add-two-numbers

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
        if(l1 == NULL && l2 == NULL){
            return NULL;
        }

        ListNode* res = new ListNode();
        ListNode* dummy = res;
        int rem = 0;

        //till l1 nad l2 contains node
        while(l1 != NULL && l2 != NULL){

            // Quotient (2+5+0)%10 = 7
            int quotient = (l1->val + l2->val + rem) % 10; //(2+5+0)%10, (4+6+0)%10, (3+4+1)%10
            // Reaminder (2+5+0)/10 = 0
            rem = (l1->val + l2->val + rem) / 10; //(2+5+0)/10, (4+6+0)/10, (3+4+1)/10
            
            ListNode* temp = new ListNode(quotient);
            res->next = temp;
            res = res->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        // if l1 still contains node
        while(l1 != NULL){
            int quotient = (l1->val + rem) % 10;
            rem = (l1->val + rem) / 10;
            ListNode* temp = new ListNode(quotient);
            res->next = temp;
            res = res->next;
            l1 = l1->next;
        }

        // if l2 still contains node
        while(l2 != NULL){
            int quotient = (l2->val + rem) % 10;
            rem = (l2->val + rem) / 10;
            ListNode* temp = new ListNode(quotient);
            res->next = temp;
            res = res->next;
            l2 = l2->next;
        }

        // if remainder has some value then craete new node
        if(rem > 0){
            ListNode* temp = new ListNode(rem);
            res->next = temp;
            res = res->next;            
        }
        return dummy->next;
    }
};