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
    //sol 1:
    /*
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
    }*/

    //sol 2:
    pair<bool, int> isBalancedfast(TreeNode* root){
        pair<bool, int> ans = make_pair(true, 0);
        if(root == NULL){
            return ans;
        }

        pair<bool, int> left = isBalancedfast(root->left);
        pair<bool, int> right = isBalancedfast(root->right);


        ans.second = max(left.second , right.second) + 1;
        
        if(left.first && right.first && abs(left.second - right.second) <= 1){
            ans.first = true;
        }
        else{
            ans.first = false;
        }

        return ans;

    }
    bool isBalanced(TreeNode* root) {
        return isBalancedfast(root).first;
    }
};