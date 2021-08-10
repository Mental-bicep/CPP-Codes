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
#include<bits/stdc++.h>
#define rn return 
#define v vector
#define pb push_back
using namespace std;
class Solution {
public:
    void fun(TreeNode *root,v<int> &v1)
    {
        if(root==NULL) rn;
        if(root->left==NULL and root->right==NULL) 
            v1.pb(root->val);
        fun(root->left,v1);
        fun(root->right,v1);
        rn;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        v<int> v1,v2;
        fun(root1,v1);
        fun(root2,v2);
        // for(auto &ele:v1) cout<<ele<<" ";
        // cout<<"\n";
        // for(auto &ele:v2) cout<<ele<<" ";
        // cout<<"\n";
        if(v1==v2) rn true;
        rn false;
    }
};
