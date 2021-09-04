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
    bool fun(TreeNode *root,int val){
        if(root==NULL) return true;
        if(root->val!=val) return false;
        if(fun(root->left,val) and fun(root->right,val)) return true;
        return false;
    }
    bool isUnivalTree(TreeNode* root) {
        if(root==NULL) return true;
        bool ans=fun(root,root->val);
        return ans;
    }
};
