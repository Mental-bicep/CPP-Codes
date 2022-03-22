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
    
    int getMax(TreeNode *root)
    {
        while(root->right) root=root->right;
        return root->val;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(key<root->val) root->left=deleteNode(root->left,key);
        else if(key>root->val) root->right=deleteNode(root->right,key);
        else{
            if(root->right and root->left){
                int val=getMax(root->left);
                root->val=val;
                root->left=deleteNode(root->left,val);
            }
            else if(root->left) return root->left;
            else if(root->right) return root->right;
            else return NULL;
        }
        return root;
    }
    
};
