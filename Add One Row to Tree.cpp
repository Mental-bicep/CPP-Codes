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
    
    void fun(TreeNode *root,int val,int depth,int cdepth)
    {
        if(!root) return ;
        if(cdepth==(depth-1))
        {
            TreeNode *left=new TreeNode(val);
            TreeNode *right=new TreeNode(val);
            left->left=root->left;
            right->right=root->right;
            root->left=left;
            root->right=right;
            return ;
        }
        fun(root->left,val,depth,cdepth+1);
        fun(root->right,val,depth,cdepth+1);
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode *nroot=new TreeNode(val);
            nroot->left=root;
            return nroot;
        }
        fun(root,val,depth,1);
        return root;
        // return fun(root,val,depth,cdepth);
    }
};
