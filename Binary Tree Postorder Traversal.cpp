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
class Pair{
    public:
    TreeNode * node;
    bool sd,ld,rd;
    Pair(TreeNode *node){
        this->node=node;
        sd=ld=rd=false;
    }
};


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<Pair> st;
        st.push(Pair(root));
        vector<int> res;
        while(st.size()>0)
        {
            Pair rem=st.top();st.pop();
            if(rem.node==NULL) continue;
            
            if(rem.ld==false)
            {
                rem.ld=true;
                st.push(rem);
                st.push(Pair(rem.node->left));
            }
            else if(rem.rd==false)
            {
                rem.rd=true;
                st.push(rem);
                st.push(Pair(rem.node->right));
            }
            else if(rem.sd==false)
            {
                rem.sd=true;
                res.push_back(rem.node->val);
                st.push(rem);
            }
            
            
        }
        return res;   
    }
};
