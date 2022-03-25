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
class Pair{
    public:
  int left,right,maxLen;
    Pair(int left,int right)
    {
        this->left=left;
        this->right=right;
        this->maxLen=0;
    }
};


class Solution {
public:
    // variant
    
    Pair fun(TreeNode *root) // left,right
    {
        if(!root) return Pair(-1,-1);
        auto lans=fun(root->left);
        auto rans=fun(root->right);
        Pair myans(0,0);
        myans.left=lans.right+1;
        myans.right=rans.left+1;
        myans.maxLen=max({myans.left,myans.right,lans.maxLen,rans.maxLen});
        return myans;
        
    }
    int longestZigZag(TreeNode* root) {
        Pair ans=fun(root);
        return ans.maxLen;
    }
};
