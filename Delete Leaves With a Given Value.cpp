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
class Solution {
public:
    TreeNode * fun(TreeNode *root,int tar){
        if(!root) rn root;
        root->left=fun(root->left,tar);
        root->right=fun(root->right,tar);
        if(!root->left and !root->right and root->val==tar) rn NULL;
        rn root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        rn fun(root,target);
    }
};
