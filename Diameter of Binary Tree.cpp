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
    pair<int,int> fun(TreeNode *root)   // height,dia
    {
        if(!root) return {-1,0};
        auto lans=fun(root->left);
        auto rans=fun(root->right);
        pair<int,int> myans;
        myans.first=max(lans.first,rans.first)+1;
        myans.second=max({lans.second,rans.second,lans.first+rans.first+2});
        return myans;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        auto ans=fun(root);
        return ans.second;
    }
};
