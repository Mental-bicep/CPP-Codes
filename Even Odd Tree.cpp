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
    
    bool fun(TreeNode *root,int lvl,unordered_map<int,int> &mp1)
    {
        if(!root) return true;
        if(lvl&1)
        {
            if((root->val&1)) return false;
            if(mp1.find(lvl)==mp1.end()) mp1[lvl]=INT_MAX;
            if(mp1[lvl]<=root->val) return false;
            mp1[lvl]=root->val;
        }
        else{
            if((root->val&1)==0) return false;
            if(mp1.find(lvl)==mp1.end()) mp1[lvl]=INT_MIN;
            if(mp1[lvl]>=root->val) return false;
            mp1[lvl]=root->val;
        }
        if(!fun(root->left,lvl+1,mp1)) return false;
        if(!fun(root->right,lvl+1,mp1)) return false;
        return true;
    }
    
    bool isEvenOddTree(TreeNode* root) {
        unordered_map<int,int> mp1;
        return fun(root,0,mp1);
    }
};
