// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //inorder = [9,3,15,20,7]  Left->Root->Right
        //postorder = [9,15,7,20,3]  Left->Right->Root
        if(postorder.size() == 0 || inorder.size()==0){
            return NULL;
        }
        
        TreeNode* tree = new TreeNode();
        vector<int> inorder_left, inorder_right;
        bool root = false;
        
        tree->val = postorder[postorder.size()-1];

        //inorder
        for(int i : inorder){
            //inorder_left
            if(!root && (i != postorder[postorder.size()-1])){
                inorder_left.push_back(i);
            }
            else if(i == postorder[postorder.size()-1]){
                root = true;
                continue;
            }
            else if(root){
                inorder_right.push_back(i);
            }
        }

        //postorder
        vector<int> postorder_left, postorder_right;
        postorder_left.insert(postorder_left.end(), postorder.begin(), postorder.end()-inorder_right.size()-1);
        postorder_right.insert(postorder_right.end(), postorder.begin()+inorder_left.size(), postorder.end()-1);

        tree->left = buildTree(inorder_left, postorder_left);
        tree->right = buildTree(inorder_right, postorder_right);

        return tree;
    }
};