// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal

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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        //preorder = [8,5,1,7,10,12]
        //inorder = [1,5,7,8,10,12]
        vector<int> inorder = preorder;
        std::sort(inorder.begin(), inorder.end());
        return subBstFromPreorder( preorder, inorder);        
    }

    TreeNode* subBstFromPreorder(vector<int>& preorder, vector<int>& inorder){
        if(preorder.size() == 0 || inorder.size() == 0){
            return NULL;
        }
        
        TreeNode* tree = new TreeNode();
        int root = preorder[0];
        bool found = false;
        vector<int> left_inorder, right_inorder;
        for(int i= 0; i< inorder.size(); i++){
            if(!found && inorder[i] != root){
                left_inorder.push_back(inorder[i]);
            }
            else if(inorder[i] == root){
                found = true;
                tree->val = root;
                continue;
            }
            else if(found){
                right_inorder.push_back(inorder[i]);
            }
        }

        vector<int> preorder_left, preorder_right;
        preorder_left.insert(preorder_left.end(), preorder.begin()+1, preorder.end()-right_inorder.size());
        preorder_right.insert(preorder_right.end(), preorder.begin()+left_inorder.size()+1, preorder.end());

        tree->left = subBstFromPreorder(preorder_left, left_inorder);
        tree->right = subBstFromPreorder(preorder_right, right_inorder);
        return tree;
    }    
};