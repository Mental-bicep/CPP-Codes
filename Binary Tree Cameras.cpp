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
    int MinCamerasInBT(TreeNode *root,int &cnt)
{
    if(!root) return 1;
    int lans=MinCamerasInBT(root->left,cnt);
    int rans=MinCamerasInBT(root->right,cnt);
    // int ans;
    if(lans==-1 or rans==-1){
        ++cnt;
        return 0;
    }
    else if(lans==0 or rans==0) return 1;
    else return -1;
    
    // return 0;
}
    
    int minCameraCover(TreeNode* root) {
        int cnt=0;
        int ans=MinCamerasInBT(root,cnt);
        if(ans==-1) ++cnt;
        return cnt;
    }
};
