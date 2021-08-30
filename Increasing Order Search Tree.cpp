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
    TreeNode *curr=new TreeNode(0);
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *temp=curr;
        inorder(root);
        return temp->right;
    }
    void inorder(TreeNode *root){
        if(root==NULL) return;  // practice inorder on paper
        inorder(root->left);
        curr->right=root;
        root->left=NULL;
        curr=curr->right;
        inorder(root->right);
    }
};
