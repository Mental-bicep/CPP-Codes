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
    
    TreeNode *fun(vector<int> &preorder,int psi,int pei,vector<int> &inorder,int isi,int iei,unordered_map<int,int > &mp1)
    {
        if(psi>pei ) return NULL;
        TreeNode *node=new TreeNode(preorder[psi]);
        int idx=mp1[preorder[psi]];
        int cnt=idx-isi;
        node->left=fun(preorder,psi+1,psi+cnt,inorder,isi,idx-1,mp1);
        node->right=fun(preorder,psi+cnt+1,pei,inorder,idx+1,iei,mp1);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0) return NULL;
        unordered_map<int,int> mp1;
        for(int i=0;i<inorder.size();++i) mp1[inorder[i]]=i;
        return fun(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp1);
    }
};
