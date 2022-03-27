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
    
    TreeNode *fun(vector<int> &preorder,int li,int ri,int &idx)
{
    if(idx==preorder.size()) return NULL;
    int ele=preorder[idx];
    if(ele<=li or ele>=ri) return NULL;
    ++idx;
    TreeNode *node=new TreeNode(ele);
    node->left=fun(preorder,li,ele,idx);
    node->right=fun(preorder,ele,ri,idx);
    return node;
}
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx=0;
    return fun(preorder,INT_MIN,INT_MAX,idx);
    }
};
