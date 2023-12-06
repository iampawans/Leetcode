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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(list1 == NULL){
            return list2;
        }

        if(list2 == NULL){
            return list1;
        }

        
        struct ListNode* tmp;
        struct ListNode* head;
        
        //fill the first element in the list
        if(list1->val > list2->val){
            tmp = new ListNode(list2->val);
            list2 = list2->next;
        }
        else {
            tmp = new ListNode(list1->val);
            list1 = list1->next;                
        }

        
        head = tmp;

        //insert the elements in the sorted order
        while(list1 && list2){
            
            if(list1->val > list2->val){
                tmp->next = list2;
                list2 = list2->next;
            }
            else {
                tmp->next = list1;
                list1 = list1->next;              
            }
            tmp = tmp->next;
        }

        if(!list1){
            tmp->next = list2;
        }
        if(!list2){
            tmp->next = list1;
        }

        return head;
    }
};