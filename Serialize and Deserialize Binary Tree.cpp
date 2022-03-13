/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    void encode(TreeNode *root,string &ans)
    {
        if(root==NULL) {
            ans+="N ";
            return ;
        }
        ans+=to_string(root->val)+" ";
        encode(root->left,ans);
        encode(root->right,ans);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
         encode(root,ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode *fun(vector<string> &word,int &idx)
    {   
        
        if(idx==word.size()) return NULL;
        if(word[idx]=="N") {idx++;return NULL;}
        TreeNode *node=new TreeNode(stoi(word[idx]));
        idx++;
        node->left=fun(word,idx);
        node->right=fun(word,idx);
        return node;
    }
    
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string word;
        vector<string> v1;
        while(ss>>word) v1.push_back(word);
        int idx=0;
        return fun(v1,idx);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
