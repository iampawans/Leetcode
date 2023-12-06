// https://leetcode.com/problems/binary-tree-right-side-view

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
    /*
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root == NULL){
            return result;
        }

        map<int, map<int, vector<int>>> mp;
        queue<pair<int, pair<int, TreeNode*>>> q;
        q.push(make_pair(0, make_pair(0, root)));

        while(!q.empty()){
            auto qNode = q.front();
            q.pop();

            int row = qNode.first;
            int col = qNode.second.first;
            TreeNode* node = qNode.second.second;

            mp[row][col].push_back(node->val);

            if(node->left){
                q.push(make_pair(row +1, make_pair(col -1, node->left)));
            }
            if(node->right){
                q.push(make_pair(row +1, make_pair(col +1, node->right)));
            }
        }

        for(auto m : mp){
            for (auto it = m.second.rbegin(); it != m.second.rend(); ++it) {
                result.push_back(it->second[it->second.size()-1]);
                break;
            }
        }

        return result;
    }
    */
    void solve(TreeNode* root, vector<int> &ans, int level){
        if(root == NULL){
            return;
        }

        if(level == ans.size()){
            ans.push_back(root->val);
        }

        solve(root->right, ans, level +1);
        solve(root->left, ans, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};