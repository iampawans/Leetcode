// https://leetcode.com/problems/binary-tree-inorder-traversal

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> in;
        if(root == NULL){
            return in;
        }
        auto v1 = inorderTraversal(root->left);
        in.insert(in.end(), v1.begin(), v1.end());
        in.push_back(root->val);
        auto v2 = inorderTraversal(root->right);
        in.insert(in.end(), v2.begin(), v2.end());
        return in;
    }
};