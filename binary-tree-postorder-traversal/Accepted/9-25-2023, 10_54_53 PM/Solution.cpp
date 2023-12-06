// https://leetcode.com/problems/binary-tree-postorder-traversal

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> post;
        if(root == NULL){
            return post;
        }

        //Left->Right->Root
        auto v1 = postorderTraversal(root->left);
        post.insert(post.end(), v1.begin(), v1.end());
        auto v2 = postorderTraversal(root->right);
        post.insert(post.end(), v2.begin(), v2.end());
        post.push_back(root->val);

        return post;
    }
};