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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return vector<int>{};
    queue<TreeNode*> q;
    q.push(root);
    vector<int> res;
    while(q.size()>0)
    {
        int size=q.size();
        auto rem=q.front();
        res.push_back(rem->val);
        // cout<<rem->val<<"\n";
        while(size--)
        {
            auto ele=q.front();q.pop();
            if(ele->right) q.push(ele->right);
            if(ele->left) q.push(ele->left);
        }
    }
    return  res;
    }
};
