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
    
    TreeNode* fun(vector<int> & preorder,int psi,int pei,vector<int>&postorder,int ppsi,int ppei,unordered_map<int,int> &mp1)
{
    if(psi>pei) return NULL;
    if(psi==pei) return new TreeNode(preorder[psi]);
    TreeNode* node=new TreeNode(preorder[psi]);
    int ele=preorder[psi+1];
    int idx=mp1[ele];
    int tne=idx-ppsi+1;
    node->left=fun(preorder,psi+1,psi+tne,postorder,ppsi,idx,mp1);
    node->right=fun(preorder,psi+tne+1,pei,postorder,idx+1,ppei-1,mp1);
    return node;
}
    
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        
        unordered_map<int,int> mp1;
    for(int i=0;i<post.size();++i) 
        mp1[post[i]]=i;
    return fun(pre,0,pre.size()-1,post,0,post.size()-1,mp1);
    }
};
