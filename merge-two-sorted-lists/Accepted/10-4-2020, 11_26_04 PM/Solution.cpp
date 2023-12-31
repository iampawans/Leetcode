// https://leetcode.com/problems/merge-two-sorted-lists

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
        

        ListNode* temp;
        ListNode* nd;
        
        if(!l1)
            return l2;
        if(!l2)
            return l1;     
        
        // fill temp with the first node
        if(l1->val < l2->val)
        {
            temp = new ListNode(l1->val, l1->next);
            l1 = l1->next;
        }
        else
        {
            temp = new ListNode(l2->val, l2->next);
            l2 = l2->next;            
        }
        
        nd = temp;

        //assign the temp with the sorted data
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                temp->next = l1;
                l1 = l1->next;
            }
            else
            {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        
        temp->next = l1 ? l1:l2;
        return nd;
    }
};