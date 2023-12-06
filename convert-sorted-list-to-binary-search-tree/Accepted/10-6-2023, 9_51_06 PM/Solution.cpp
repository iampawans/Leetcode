// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
/*
    void insertBefore(ListNode** head, int val){
        cout << "insertBefore val : " << val << endl;
        ListNode* newNode= new ListNode();
        newNode->val = val;
        newNode->next = *head;
        *head = newNode;
    }

    void insertAfter(ListNode** head, int val){
        cout << "insertAfter val : " << val << endl;
        ListNode* newNode= new ListNode();
        newNode->val = val;
        newNode->next = NULL;

        ListNode* tmp = *head;
        if(*head == NULL){
            *head = newNode;
            return;
        }

        while(tmp->next != NULL){
            tmp =tmp->next;
        }

        tmp->next = newNode;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
            return NULL;
        
        ListNode* tmp = head;
        ListNode* tmp1 = head;
        TreeNode* tree = new TreeNode();
        //Get Number of elements
        int count =0;
        while(tmp != NULL){
            count++;
            tmp = tmp->next;
        }

        ListNode* left = NULL;
        ListNode* right = NULL;

        int mid = count/2 +1;
        cout << "count : " << count << " mid : " << mid << endl;
        while(tmp1 != NULL){
            if(count > mid){
                cout << "Before insertBefore" << endl;
                insertBefore(&left, tmp1->val);
            }
            else if(count == mid){
                cout << "count == mid -> tmp1->val : " << tmp1->val << endl;
                tree->val = tmp1->val;
            }
            else{
                cout << "Before insertAfter" << endl;
                insertBefore(&right, tmp1->val);
            }
            tmp1 = tmp1->next;
            count--;
        }
        ListNode* l = left;
        while(l != NULL){
            cout << "l->val : " << l->val << endl;
            l = l->next;
        }
        ListNode* r = right;
        while(r != NULL){
            cout << "r->val : " << r->val << endl;
            r = r->next;
        }
        tree->left = sortedListToBST(left);
        tree->right = sortedListToBST(right);
        return tree;
    }
    */
    TreeNode* sortedListToBST(ListNode *head){
    	return semiSortedListToBST( head, NULL );
    }

    TreeNode* semiSortedListToBST(ListNode* head, ListNode* tail){
        if(head == tail){
            return NULL;
        }

        //find middle
        ListNode* tmp = head;
        ListNode* mid=head;
        while(tmp != tail && tmp->next != tail){
            mid = mid->next;
            tmp = tmp->next->next;
        }

        //create Tree
        TreeNode* tree = new TreeNode();
        tree->val = mid->val;
        tree->left = semiSortedListToBST(head, mid);
        tree->right = semiSortedListToBST(mid->next, tail);
        return tree;
    }

};