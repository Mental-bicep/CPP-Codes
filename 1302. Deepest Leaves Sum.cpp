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
#define f first
#define s second
class Solution {
public:
    unordered_map<int,int> mp1;
    void fun(TreeNode *root,int h){
        if(root==NULL) return ;
        mp1[h]+=root->val;
        fun(root->left,h+1);
        fun(root->right,h+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        fun(root,0);
        int ans1=LLONG_MIN,ans2=ans1;
        for(auto &ele:mp1) if(ele.f>ans1){
            ans1=ele.f;
            ans2=ele.s;
        }
        return ans2;
    }
};
