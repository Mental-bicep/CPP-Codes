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
class CBTInserter {
public:
    queue<TreeNode*> q;
    TreeNode *root;
    CBTInserter(TreeNode* root) {
        q.push(root);
        this->root=root;
        while(true)
        {
            TreeNode *rem=q.front();
            if(rem->left) q.push(rem->left);
            else break;
            if(rem->right) {
                q.push(rem->right);
                q.pop();
            }
            else break;
        }
    }
    
    int insert(int val) {
        auto ele=q.front();
        if(ele->left==NULL){
            TreeNode *node=new TreeNode(val);
            ele->left=node;
            q.push(node);
            return ele->val;
        }
        else {
            TreeNode *node=new TreeNode(val);
            ele->right=node;
            q.push(node);
            q.pop();
            return ele->val;
        }
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
