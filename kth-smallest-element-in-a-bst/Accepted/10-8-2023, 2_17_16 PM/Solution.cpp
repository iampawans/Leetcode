// https://leetcode.com/problems/kth-smallest-element-in-a-bst

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
    vector<int> inorder(TreeNode* root){
        vector<int> res;
        if(root == NULL){
            return res;
        }
        

        vector<int> v1 = inorder(root->left);
        res.insert(res.end(), v1.begin(), v1.end());
        res.push_back(root->val);
        vector<int> v2 = inorder(root->right);
        res.insert(res.end(), v2.begin(), v2.end());

        return res;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> elements = inorder(root);

        return elements[k-1];
    }
};