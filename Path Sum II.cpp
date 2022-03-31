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
    void fun(TreeNode *node,int sum,vector<int>&temp,vector<vector<int>> &ans )
{
    if(!node) return ;
    if(!node->left and !node->right) {
        // return sum-node->val==0?true:false;
        if(sum-node->val==0) {
            temp.emplace_back(node->val);
            ans.push_back(temp);
            temp.pop_back();
        }
        return ;
    }
    temp.emplace_back(node->val);
     fun(node->left,sum-node->val,temp,ans) ;
     temp.pop_back();
     temp.emplace_back(node->val);
     fun(node->right,sum-node->val,temp,ans);
     temp.pop_back();
}
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
  vector<vector<int>> ans;
  fun(root,targetSum,temp,ans);
  return ans;
    }
};
