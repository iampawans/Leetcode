// https://leetcode.com/problems/merge-k-sorted-lists

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;

        if(lists.size() == 1)
            return lists.at(0); 

        ListNode* new_list = NULL;
        ListNode* dummy_list;
        ListNode* tmp;

        for(ListNode* list : lists){
            if(!list){
                continue;
            }

            if(new_list && (new_list->val < list->val)){
                tmp = new ListNode(new_list->val);
                new_list = new_list->next;
            }
            else{
                tmp = new ListNode(list->val);
                list = list->next;
            }
            dummy_list = tmp;

            while(new_list && list){
                if(new_list->val >= list->val){
                    tmp->next = list;
                    list = list->next;
                }
                else {
                    tmp->next = new_list;
                    new_list = new_list->next;
                }
                tmp = tmp->next;
            }

            if(!list){
                tmp->next = new_list;
            }
            if(!new_list){
                tmp->next = list;
            }
            new_list = dummy_list;

        }

        return new_list;
    }
};