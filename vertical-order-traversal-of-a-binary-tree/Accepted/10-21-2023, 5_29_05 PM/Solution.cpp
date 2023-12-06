// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        std::map<int, map<int, vector<int>>> mp;
        if(root == NULL){
            return result;
        }
        
        //int col = 0;
        queue<pair<int, pair<int, TreeNode*>>> q;
        q.push(make_pair(0, make_pair(0, root)));

        while(!q.empty()){
            
            auto node = q.front();
            q.pop();

            int row = node.first;
            int col = node.second.first;
            auto tmpNode = node.second.second;

            mp[col][row].push_back(tmpNode->val);
            std::sort(mp[col][row].begin(), mp[col][row].end());
            
            if(tmpNode->left){
                q.push(make_pair(row+1, make_pair(col-1, tmpNode->left)));
            }
            if(tmpNode->right){
                q.push(make_pair(row+1, make_pair(col+1, tmpNode->right)));
            }
        }
        for(auto entries : mp){
            vector<int> tmp;
            for(auto i : entries.second){
                for(auto j : i.second){
                    tmp.push_back(j);
                }
            }
            result.push_back(tmp);
        }
        return result;
    }
};