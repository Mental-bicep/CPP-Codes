#define rn return
#define umap unordered_map
#define v vector
#define pb push_back
#define ppb pop_back
#define s second 
#define f first 
class Solution {
public:
    void fun(umap<int,int>&mp1,int cnt,v<v<int>>&res,v<int>&ans)
    {
            if(cnt==0)
            {
                res.pb(ans);
                rn;
            }
        
            for(auto &ele:mp1)
            {
                if(ele.s==0) continue;
                ele.s-=1;
                ans.pb(ele.f);
                fun(mp1,cnt-1,res,ans);
                ans.ppb();
                ele.s+=1;
            }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        umap<int,int> mp1;
        int cnt=0;
        for(auto &ele:nums) {
            ++cnt;
            ++mp1[ele];
        }
        v<v<int>> res;
        v<int> ans;
        fun(mp1,cnt,res,ans);
        rn res;
    }
};
