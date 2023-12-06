// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //preorder = [3,9,20,15,7]  Root->Left->Right
        //inorder = [9,3,15,20,7]  Left->Root->Right
        TreeNode* tree = new TreeNode();
        if (preorder.size() == 0 || inorder.size()== 0){
            return NULL;
        }

        tree->val = preorder[0];
        vector<int> inorder_left, inorder_right;
        bool root= false;


        // inroder
        for(int i : inorder){
            // fill inorder_left
            if(!root && i != preorder[0]){
                inorder_left.push_back(i);
            }
            else if(i == preorder[0]){
                root = true;
                continue;
            }

            // fill inorder_right
            if(root){
                inorder_right.push_back(i);
            }
        }

        // preoredr
        vector<int> preorder_left, preorder_right;
        preorder_left.insert(preorder_left.end(), preorder.begin()+1, preorder.end()-inorder_right.size());        
        preorder_right.insert(preorder_right.end(), preorder.begin()+inorder_left.size()+1, preorder.end());


        //Fill tree->left
        tree->left = buildTree(preorder_left, inorder_left);
        //Fill tree->right
        tree->right = buildTree(preorder_right, inorder_right);
        return tree;
    }
};