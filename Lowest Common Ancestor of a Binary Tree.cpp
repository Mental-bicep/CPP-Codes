/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *lca;
    bool fun(TreeNode *root,int p,int q)
{
    if(!root) return false;
    bool self= root->val==p or root->val==q;
    
    bool lans=fun(root->left,p,q);
    if(lca!=NULL) return true; // imptt
    bool rans=fun(root->right,p,q);
    if(lca!=NULL) return true;  // imptt
    if((self and lans) or (self and rans) or (lans and rans)) lca=root;
    return self or lans or rans;
}
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
     lca=NULL;
        fun(root,p->val,q->val);
        return lca;
    }
};
