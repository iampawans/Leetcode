// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() ==0){
            return NULL;
        }
        TreeNode* tree= new TreeNode();
        int r = nums[nums.size()/2];
        tree->val = r;
        vector<int> nums_left, nums_right;
        bool root = false;

        for(int i : nums){
            if(!root && i != r){
                nums_left.push_back(i);
            }
            else if( i ==  r){
                root = true;
                continue;
            }
            else if(root){
                nums_right.push_back(i);
            }
        }
        tree->left = sortedArrayToBST(nums_left);
        tree->right = sortedArrayToBST(nums_right);
        return tree;
    }
};