// https://leetcode.com/problems/balanced-binary-tree

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
    int isHeightbalanced(TreeNode* root, bool &ans){
        if(root == NULL){
            return 0;
        }

        int left = isHeightbalanced(root->left, ans);
        int right = isHeightbalanced(root->right, ans);

        cout << abs(left - right) << endl;
        if(abs(left - right) > 1){
            ans = false;
        }

        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        int i = isHeightbalanced(root , ans);
        return ans;
    }
};