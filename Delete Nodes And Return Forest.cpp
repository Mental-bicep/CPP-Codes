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
    TreeNode* fun(TreeNode *root,unordered_map<int,bool> &mp1,vector<TreeNode*> &ans)
    {
        if(root==NULL) return  root;
        root->left=fun(root->left,mp1,ans);
        root->right=fun(root->right,mp1,ans);
        if(mp1[root->val]) {
            if(root->left) ans.push_back(root->left);
            if(root->right) ans.push_back(root->right);
            return NULL;
        }
        return root;
        
        
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode* >v1;
        // v1.push_back(root);
        unordered_map<int,bool> mp1;
        for(auto &ele:to_delete) mp1[ele]=true;
        fun(root,mp1,v1);
        if(mp1[root->val]==false) v1.push_back(root);
        // if(mp1[root->val]) {
        //     if(root->left) v1.push_back(root->left);
        //     if(root->right) v1.push_back(root->right);
        //     // return NULL;
        // }
        return v1;
    }
};
