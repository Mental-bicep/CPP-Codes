#define umap unordered_map
#define v vector
class Solution {
public:
    void fun(v<int>&v1,v<v<int>>&res,v<int>&ans,umap<int,bool>&mp1,int i)
    {
        if(i==v1.size())
        {
            res.push_back(ans);
            return ;
        }
        
        for(int j=0;j<v1.size();++j)
        {
            if(mp1[j]) continue;
            mp1[j]=true;
            ans.push_back(v1[j]);
            fun(v1,res,ans,mp1,i+1);
            ans.pop_back();
            mp1[j]=false;
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        umap<int,bool> mp1;
        vector<int> ans;
        fun(nums,res,ans,mp1,0);
        return res;
    }
};
