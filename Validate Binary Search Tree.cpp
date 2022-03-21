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
#define ll long long 
class Solution {
public:
    bool fun(TreeNode* root,ll si, ll ei)
    {
        if(!root) return true;
        if(root->val<=si or root->val>=ei) return false;
        // if(root->val<si or root->val>ei) return false;
        if(!fun(root->left,si,root->val) ) return false;
        if( !fun(root->right,root->val,ei) ) return false;
        return true;
    }
    
    bool isValidBST(TreeNode* root) {
        return fun(root,LLONG_MIN,LLONG_MAX);
    }
};
