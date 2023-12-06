// https://leetcode.com/problems/linked-list-cycle

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        struct ListNode* tmp = head;
 
        while(tmp != NULL && tmp->next != NULL){

            head = head->next;
            tmp = tmp->next->next;

            if(head == tmp){
                return true;
            }
            
        }
        return false;
    }
};
