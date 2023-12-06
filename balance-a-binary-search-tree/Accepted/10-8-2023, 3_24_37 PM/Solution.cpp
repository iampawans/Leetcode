// https://leetcode.com/problems/balance-a-binary-search-tree

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

    TreeNode* createTree(vector<int> elements){
        if(elements.size() == 0){
            return NULL;
        }
        TreeNode* tree = new TreeNode();
        int mid = elements.size()/2;
        cout << "mid : " << mid << endl;
        vector<int> v_l(elements.begin(), elements.begin()+mid);
        vector<int> v_r(elements.begin()+mid+1, elements.end());

        tree->val = elements[mid];
        cout << "elements[mid] : " << elements[mid] << endl;
        tree->left = createTree(v_l);
        tree->right = createTree(v_r);

        return tree;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> elements = inorder(root);
        return createTree(elements);
    }
};