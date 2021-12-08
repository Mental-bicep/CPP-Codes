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
#define rn return 
#define ll int
class Solution {
public:
    void fun(TreeNode *root,TreeNode *par,TreeNode *gpar,int &ans){
        if(!root) rn;
        if(gpar and (gpar->val)%2==0) ans+=root->val;
        // if(gpar==NULL) {
            fun(root->left,root,par,ans);
            fun(root->right,root,par,ans);
        // }
        // else{
        //     if((gpar->val)%2==0) ans+=gpar->val;
        //     fun(root->left,root,par,ans);
        //     fun(root->left,root,par,ans);
        // }
    }
    int sumEvenGrandparent(TreeNode* root) {
        if(!root) rn 0;
        ll ans=0;
        fun(root->left,root,NULL,ans);
        fun(root->right,root,NULL,ans);
        rn ans;
    }
};
