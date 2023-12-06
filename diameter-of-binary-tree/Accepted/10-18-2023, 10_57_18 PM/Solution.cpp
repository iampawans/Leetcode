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
    pair<int, int> fastDiameterOfBinaryTree(TreeNode* root){
        //tmp[0] = diameter
        //tmp[1] = height of tree
        pair<int,int> ans = make_pair(0, 0);
        if(root == NULL){
            return ans;
        }


        pair<int,int> left = fastDiameterOfBinaryTree(root->left);
        pair<int,int> right = fastDiameterOfBinaryTree(root->right);

        int opt1 = left.first;
        int opt2 = right.first;
        int opt3 = left.second + right.second;

        ans.first = max(opt3, max(opt1 , opt2));
        ans.second = max(left.second, right.second) + 1;

        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        auto tmp = fastDiameterOfBinaryTree(root);
        return tmp.first;
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