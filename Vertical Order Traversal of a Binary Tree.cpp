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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<int,vector<int>> mp1;
        queue<pair<TreeNode*,int>>  q;
        q.push(make_pair(root,0));
        int mn=INT_MAX;
        while(q.size()>0)
        {   int size=q.size();
            unordered_map<int,vector<int>> mp2;   
         while(size--){
                auto rem=q.front();q.pop();
                mp2[rem.second].push_back(rem.first->val);
             mn=min(mn,rem.second);
                if(rem.first->left) q.push(make_pair(rem.first->left,rem.second-1));
            if((rem.first->right)) q.push(make_pair(rem.first->right,rem.second+1));
                }
            for(auto &ele:mp2)
            {
                sort(ele.second.begin(),ele.second.end());
                for(auto &itms:ele.second) mp1[ele.first].push_back(itms);
            }
        }
        vector<vector<int>> res;
        for(int i=1;i<=mp1.size();++i) res.push_back(mp1[mn++]);
        return res;
    }
};
