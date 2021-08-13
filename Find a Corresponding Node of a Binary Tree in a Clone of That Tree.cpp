/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define rn return 
TreeNode* fun(TreeNode*t1,TreeNode*t2)
{
    // if(t1==t2==NULL) return t1;
    if(t1==NULL) rn t1;
    if(t1->val==t2->val) return t1;
    // else if(t1->val>t2->val) rn fun(t1->left,t2);
    // else rn fun(t1->right,t2);
    auto ans1=fun(t1->left,t2);
    if(ans1) rn ans1;
    ans1=fun(t1->right,t2);
    rn ans1;
    
}
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        auto ans=fun(cloned,target);
        return ans;
    }
};
