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
    int ans;
    int decimal(string s1){
        if(s1.size()==0) return 0;
        reverse(s1.begin(),s1.end());
        int t_ans=0;
        for(int i=0;i<s1.size();++i)
            t_ans+=pow(2,i)*(s1[i]-'0');
        return t_ans;
    }
    void fun(TreeNode *root,string &s1){
        if(root==NULL) return ;
        s1.push_back(root->val+'0');
        if(root->left==NULL and root->right==NULL) {
            // cout<<s1<<" "<<decimal(s1)<<"\n";
            ans+=decimal(s1);
                                                        
        }
        else {fun(root->left,s1);
        fun(root->right,s1);
             }
        s1.pop_back();
    }
    int sumRootToLeaf(TreeNode* root) {
        ans=0;
        string s1="";
        fun(root,s1);
        return ans;
    }
};
