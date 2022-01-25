class Solution {
public:
    
    int fun(int amt,vector<int>&v1,int idx,vector<vector<int>>&dp)
    {
        if(amt==0) return 1;
        if(idx==v1.size()) return 0;
        if(dp[idx][amt]!=-1) return dp[idx][amt];
        int ans=0;
        for(int i=0;amt-i*v1[idx]>=0;++i)
             ans+=fun(amt-i*v1[idx],v1,idx+1,dp);
        return dp[idx][amt]=ans;
    }
    
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        int ans=fun(amount,coins,0,dp);
        return ans;
    }
};
