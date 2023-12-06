// https://leetcode.com/problems/binary-tree-preorder-traversal

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> pre;
        if(root == NULL){
            return pre;
        }
        //Root->Left->Right
        pre.push_back(root->val);
        auto v1 = preorderTraversal(root->left);
        pre.insert(pre.end(), v1.begin(), v1.end());
        auto v2 = preorderTraversal(root->right);
        pre.insert(pre.end(), v2.begin(), v2.end());

        return pre;
    }
};