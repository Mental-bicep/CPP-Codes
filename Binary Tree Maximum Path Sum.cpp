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
    
    pair<int,int> fun(TreeNode *root)
    {
        if(!root) return {0,INT_MIN};
        auto lans=fun(root->left);
        auto rans=fun(root->right);
        pair<int,int> myans;
        myans.first=max({lans.first+root->val,rans.first+root->val,root->val});
        myans.second=max({lans.second,rans.second,myans.first,lans.first+rans.first+root->val});
        return myans;
    }
    
    
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        auto ans=fun(root);
        return ans.second;
    }
};
