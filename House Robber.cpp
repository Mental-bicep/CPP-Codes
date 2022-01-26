#include<bits/stdc++.h>
using namespace std;
#define ll int
#define v vector
class Solution {
public:
    
    int fun(v<int>&v1,int idx,v<int>&dp)
    {
        if(idx==0) return v1[idx]>0? v1[idx]:0;
        if(idx<0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int ans=v1[idx]+fun(v1,idx-2,dp);
        ans=max(ans, fun(v1,idx-1,dp) );
        return dp[idx]=ans;
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        v<ll> dp(n+1,-1);
        auto ans=fun(nums,n-1,dp);
        // cout<<ans<<"\n";
        return ans;
    }
};
