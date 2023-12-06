// https://leetcode.com/problems/remove-nth-node-from-end-of-list

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        std::stack<ListNode*> st;

        while(head){
            cout << "Push Stack : " << head->val << endl;
            st.push(head);
            head = head->next;
        }

        ListNode* tmp;
        ListNode* prev;
        while(!st.empty()){
            cout << "Inside While" << endl;
            count++;
            tmp = st.top();
            cout << "Pop Stack : " << tmp->val << endl;
            st.pop();
            if(count == n){
                prev = tmp->next;
                //cout << "Pop Stack when at pos : " << prev->val << endl;
                if(st.empty()){
                    return prev;
                }
                continue;
            }
            if(count == (n+1)){
                tmp->next = prev;
                //cout << "Pop Stack when at next pos : " << prev->val << " " << tmp->val<< endl;
            }         
        }
        return tmp;
    }
};