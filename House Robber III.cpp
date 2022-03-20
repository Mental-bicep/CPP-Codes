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
    
    pair<int,int> fun(TreeNode *root) // inc,exc
    {
        if(!root) return pair<int,int>{0,0};
        auto ans1=fun(root->left);
        auto ans2=fun(root->right);
        pair<int,int> myans;
        myans.first= root->val+ans1.second+ans2.second;
        myans.second=max(ans1.first,ans1.second)+max(ans2.second,ans2.first);
        return myans;
    }    
    int rob(TreeNode* root) {
        auto ans=fun(root);
        return max(ans.first,ans.second);
    }
};
