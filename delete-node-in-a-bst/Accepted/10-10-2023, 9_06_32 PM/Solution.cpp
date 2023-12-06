// https://leetcode.com/problems/delete-node-in-a-bst

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }

        TreeNode* temp = root;
        if(key > temp->val){
            temp->right = deleteNode(temp->right, key);
        }
        else if(key < temp->val){
            temp->left = deleteNode(temp->left, key);
        }
        else{
            //if 0 child
            if(temp->right == NULL && temp->left == NULL){
                return NULL;
            }
            //if 1 child
            if(temp->right == NULL || temp->left == NULL){
                return temp->right ? temp->right : temp->left;
            }

            //if 2 child, replace the node with either max of left or min of right tree.
            //here travel in left and find max node
            TreeNode* maxNode = temp->left;
            while(maxNode->right != NULL){
                maxNode = maxNode->right; 
            }
            temp->val = maxNode->val;     
            temp->left = deleteNode(temp->left, maxNode->val); 

            /*
            TreeNode* minNode = temp->right;
            while(maxNode->left != NULL){
                minNode = minNode->left; 
            }
            temp->val = minNode->val;     
            temp->right = deleteNode(temp->right, minNode->val); 
            */
        }
        
        return root;

    }
};