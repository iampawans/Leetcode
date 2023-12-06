// https://leetcode.com/problems/binary-tree-level-order-traversal

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> res;
        // Base condition
        if(root == NULL){
            return ans;
        }

        queue<TreeNode*> q;

        //Enter the first root node
        q.push(root);
        q.push(NULL); // Push NULL after level 1 completed
        
        while(!q.empty()){
            //pop front of the queue and store in tmp
            auto tmp = q.front();
            q.pop();

            //if level completed, insert res to ans
            if(tmp == NULL){
                ans.push_back(res); //if NULL insert res to ans
                res.clear(); // clear res vector for next level
                if(!q.empty()){ // if queue is not empty push NULL means next level completed
                    q.push(NULL);
                }
            }
            else{
                //logic to insert element of same level in vector res
                res.push_back(tmp->val);
                if(tmp->left){ // left available, insert in queue
                    q.push(tmp->left);
                }

                if(tmp->right){ // right available, insert in queue
                    q.push(tmp->right);
                }
            }
        }

        return ans;
    }
};