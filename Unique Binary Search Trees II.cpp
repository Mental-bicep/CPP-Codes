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
    
    vector<TreeNode*> fun(int si,int ei,map<pair<int,int>,vector<TreeNode*>> &mp1)
    {
        if(si>ei) return vector<TreeNode*> {NULL};
        if(mp1.find(pair<int,int>{si,ei})!=mp1.end()) return mp1[make_pair(si,ei)];
        if(si==ei) return vector<TreeNode*> {new TreeNode(si)};
        vector<TreeNode*> res;
        for(int i=si;i<=ei;++i)
        {
            auto left=i==si?vector<TreeNode*>{NULL}:fun(si,i-1,mp1);
            auto right=i==ei?vector<TreeNode*>{NULL}:fun(i+1,ei,mp1);
            for(auto &ele:left)
                for(auto &itms:right) {
                    TreeNode *node=new TreeNode(i);
                    node->left=ele;
                    node->right=itms;
                    res.push_back(node);
                }
        }
        return mp1[make_pair(si,ei)]=res;
        
    }
    
    vector<TreeNode*> generateTrees(int n) {
        // vector<vector<vector<int>>> v1(9,vector<vector<int>>(9));
        map<pair<int,int>,vector<TreeNode*>> mp1;
        return fun(1,n,mp1);
    }
};
