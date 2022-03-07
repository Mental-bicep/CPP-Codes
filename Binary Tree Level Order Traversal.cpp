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
    void fun(TreeNode *root,int lvl,unordered_map<int,vector<int>> &mp1)
    {
        if(!root) return ;
        mp1[lvl].push_back(root->val);
        fun(root->left,lvl+1,mp1);
        fun(root->right,lvl+1,mp1);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        // vector<vector<int>> res;
        unordered_map<int,vector<int>> mp1;
        fun(root,0,mp1);
        vector<vector<int>> res;
        for(int i=0;i<mp1.size();++i) res.push_back(mp1[i]);
        return res;
    }
};
