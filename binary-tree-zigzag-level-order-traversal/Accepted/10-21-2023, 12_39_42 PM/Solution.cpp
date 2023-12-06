// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> tmp;
        bool LToR = false;
        if(root == NULL){
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        LToR = true; // First level traversal done

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            if(node == NULL){
                result.push_back(tmp);
                tmp.clear();
                // Flag to indicate the zigzag
                LToR = !LToR;   
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{                
                if(LToR){
                    tmp.push_back(node->val); // LtoR, simple insert in vector
                }
                else{
                    tmp.insert(tmp.begin(), node->val); // If !LToR, insert on top
                }

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }        
        }
        return result;
    }
};