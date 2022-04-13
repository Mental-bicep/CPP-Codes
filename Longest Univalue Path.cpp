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
    pair<int,int> fun(TreeNode *root) // myans,oans
    {
        if(!root) return {0,0};
        pair<int,int> myans={0,0};
        if(root->left and root->right)
        {
            auto lans=fun(root->left);
            auto rans=fun(root->right);
            if(root->left->val==root->val) myans.first=lans.first+1;
            if(root->right->val==root->val) myans.first=max(myans.first,rans.first+1);
            myans.second=max({lans.second,rans.second,myans.first});
            if(root->left->val==root->val and root->right->val==root->val) 
                myans.second=max(myans.second,lans.first+rans.first+2);
        }
        else if(root->left) {
            auto ans=fun(root->left);
            if(root->left->val==root->val) myans.first=ans.first+1;
            myans.second=max(myans.first,ans.second);
        }
        else if(root->right)
        {
            auto ans=fun(root->right);
            if(root->right->val==root->val) myans.first=max(myans.first,ans.first+1);
            myans.second=max(myans.first,ans.second);
        }
        return myans;
    }
    
    int longestUnivaluePath(TreeNode* root) {
           auto ans=fun(root);
        return ans.second;
    }
};
