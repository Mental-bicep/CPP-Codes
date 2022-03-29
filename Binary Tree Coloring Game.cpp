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
    int fun(TreeNode* root)
    {
        if(!root) return 0;
        return 1+fun(root->left)+fun(root->right);
    }
    
    TreeNode * find(TreeNode* root,int x)
    {
        if(!root) return NULL;
        if(root->val==x) return root;
        auto ans=find(root->left,x);
        if(ans) return ans;
        ans=find(root->right,x);
        if(ans) return ans;
        return NULL;
    }
    
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        // int total=fun(root);
        TreeNode *node=find(root,x);
        int lcnt=node==NULL?0:fun(node->left);
        int rcnt=node==NULL?0:fun(node->right);
        int extra=n-lcnt-rcnt-1;
        // cout<<"lcnt rcnt and extra "<<lcnt<<" "<<rcnt<<" "<<extra<<"\n";
        if(lcnt>(n/2) or rcnt>(n/2) or extra>(n/2)) return true;
        return false;
    }
};
