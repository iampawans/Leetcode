// https://leetcode.com/problems/intersection-of-two-linked-lists

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
    int listCount(ListNode *head)
    {
        int count =0;
        while(head)
        {
            count++;
            head = head->next;
        }
        return count;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        if(headA == NULL or headB == NULL)
            return NULL;

        struct ListNode* A = headA;
        struct ListNode* B = headB;
        
        struct ListNode* listA = headA;
        struct ListNode* listB = headB;
        
        int cA = listCount(A);
        int cB = listCount(B);
        
        int c = abs(cA-cB);
        
        while(c > 0)
        {
            if(cA > cB)
            {
                c--;
                listA= listA->next;
            }
            
            if(cB > cA)
            {
                c--;
                listB = listB->next;
            }
        }
        
        struct ListNode* intersection;
        while(listA and listB)
        {
            if(listA ==listB)
            {
                intersection= listA;
                break;
            }
            
            listA=listA->next;
            listB=listB->next;
        }
        
        return intersection;
        
// // SOLUTION : 2
//         struct ListNode* A = headA;
//         struct ListNode* B = headB;


//         while(A)
//         {
//             A->val *= -1;
//             A = A->next;
//         }
        
//         while(B)
//         {
//             if(B->val < 0)
//             {
//                 while(A)
//                 {
//                     A->val *= -1;
//                     A = A->next;
//                 }                
//                 struct ListNode* temp= new ListNode(B->val);           
//                 return temp;
//             }
//             B = B->next;
//         }
//        return NULL; 
    }
};