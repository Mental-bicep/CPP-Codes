/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void inorder(TreeNode *r,vector<int>&v)
{
    if(r)
    {
        inorder(r->left,v);
        v.push_back(r->val);
        inorder(r->right,v);
    }
    return ;
}
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
            return v;
    }
};
