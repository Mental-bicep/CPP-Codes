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
    bool fun(TreeNode *node,int sum)
{
    if(!node) return false;
    if(!node->left and !node->right) return sum-node->val==0?true:false;
    return fun(node->left,sum-node->val) or fun(node->right,sum-node->val);
}
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        return fun(root,targetSum);
    }
};
