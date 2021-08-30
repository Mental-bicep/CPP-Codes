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
    TreeNode * fun(TreeNode *root1,TreeNode *root2){
        if(root1==NULL and root2==NULL) return NULL;
        else if(root1==NULL){
            TreeNode *root=new TreeNode(root2->val);
            root->left=fun(root1,root2->left);
            root->right=fun(root1,root2->right);
            return root;
        }
        else if(root2==NULL){
            TreeNode *root=new TreeNode(root1->val);
            root->left=fun(root1->left,root2);
            root->right=fun(root1->right,root2);
            return root;
        }
        else{
            TreeNode *root=new TreeNode(root1->val+root2->val);
            root->left=fun(root1->left,root2->left);
            root->right=fun(root1->right,root2->right);
            return root;
        }
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode *root=fun(root1,root2);
        return root;
    }
};
