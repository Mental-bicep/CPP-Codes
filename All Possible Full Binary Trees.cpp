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
    
    vector<TreeNode*> fun(int n,unordered_map<int,vector<TreeNode*>> &mp1)
    {
        if(mp1.find(n)!=mp1.end()) return mp1[n];
        if(n==1) return mp1[n]=vector<TreeNode*>{new TreeNode(0)};
        vector<TreeNode*> ans;
        for(int i=1;i<n;i+=2)
        {
            auto left=fun(i,mp1);
            auto right=fun(n-i-1,mp1);
            for(auto &ele:left)
            {
                for(auto &itms:right) 
                {
                    TreeNode * node=new TreeNode(0);
                    node->left=ele;
                    node->right=itms;
                    ans.push_back(node);
                }
            }
            
        }
        return mp1[n]=ans;
    }
    
    vector<TreeNode*> allPossibleFBT(int n) {
        unordered_map<int,vector<TreeNode*>> mp1;
        return fun(n,mp1);
    }
};
