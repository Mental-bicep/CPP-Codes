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
    void fun(TreeNode *root,ll &sum){
        if(!root) rn ;
        fun(root->right,sum);
        // sum+=ans1;
        root->val+=sum;
        sum=root->val;
        fun(root->left,sum);
        // rn sum;
    }
    TreeNode* bstToGst(TreeNode* root) {
        ll sum=0;   // draw diagram practice req.
        fun(root,sum);
        return root;
    }
};
