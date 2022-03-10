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
    
    TreeNode * fun(vector<int> &inorder,int isi,int iei,vector<int> &postorder,int psi,int pei,unordered_map<int,int> &mp1)
    {
        if(isi>iei) return NULL;
        if(isi==iei) return new TreeNode(postorder[pei]);
        TreeNode *node=new TreeNode(postorder[pei]);
        int idx=mp1[postorder[pei]];
        int cnt=iei-idx;
        node->right=fun(inorder,idx+1,iei,postorder,pei-cnt,pei-1,mp1);
        node->left=fun(inorder,isi,idx-1,postorder,psi,pei-cnt-1,mp1);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0) return NULL;
        unordered_map<int,int> mp1;
        for(int i=0;i<inorder.size();++i) mp1[inorder[i]]=i;
        return fun(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mp1);
    }
};
