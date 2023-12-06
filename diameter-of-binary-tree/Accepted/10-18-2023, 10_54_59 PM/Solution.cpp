// https://leetcode.com/problems/diameter-of-binary-tree

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
    vector<int> fastDiameterOfBinaryTree(TreeNode* root){
        //tmp[0] = diameter
        //tmp[1] = height of tree
        vector<int> ans(2, 0);
        if(root == NULL){
            return ans;
        }


        vector<int> left = fastDiameterOfBinaryTree(root->left);
        vector<int> right = fastDiameterOfBinaryTree(root->right);

        int opt1 = left[0];
        int opt2 = right[0];
        int opt3 = left[1] + right[1];

        ans[0] = max(opt3, max(opt1 , opt2));
        ans[1] = max(left[1], right[1]) + 1;

        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        auto tmp = fastDiameterOfBinaryTree(root);
        return tmp[0];
    }
    //diameterOfBinaryTree takes O(n)
    // height takes O(n)
    // Time complexity = O(n^2)
    /*
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int left = height(root->left);
        int right = height(root->right);

        // total height of tree = height of left/right tree + 1(root)
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        int left = diameterOfBinaryTree(root->left);
        int right = diameterOfBinaryTree(root->right);
        int tree = height(root->left) + height(root->right);

        return max(tree, max(left , right));
    }
    */
};