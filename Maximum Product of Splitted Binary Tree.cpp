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
#define mod 1000000007
class Solution {
public:
    int Sum(TreeNode *root)
    {
        if(!root) return 0;
        return root->val+Sum(root->left)+Sum(root->right);
    }
    
    long fun(TreeNode *root,long &ans,int total)
    {
        if(!root) return 0;
        long lsum=fun(root->left,ans,total);
        long rsum=fun(root->right,ans,total);
        ans=max(ans, (lsum * (total-lsum) ) );
        ans=max(ans, (rsum * (total-rsum) ) );
        return lsum+rsum+root->val;
    }
    
    int maxProduct(TreeNode* root) {
        int sum=Sum(root);
        long ans=0;
        fun(root,ans,sum);
        return ans%mod;
    }
};
