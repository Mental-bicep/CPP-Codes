/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
#define rn return 
class Solution {
public:
    int fun(Node *root){
        if(root==NULL) return 0;
        if(root->children.size()==0) return 1;
        int ans=INT_MIN;
        for(auto &ele:root->children)  ans=max(ans,fun(ele));
        // cout<<"node= "<<root->val<<" returning "<<ans+1<<"\n";
        return ans+1;
    }
    int maxDepth(Node* root) {
        int ans=fun(root);
        rn ans;
    }
};
