#include<bits/stdc++.h>
using namespace std;
#define ll int 
// #define int long long 
#define v vector
#define rn return 
#define sz size
#define fori(a,b) for(auto i=a;i<b;++i)

class Solution {
public:
    
    int fun(v<ll>&v1,v<ll>&dp,ll idx)
    {   
        if(idx==0) return dp[idx]=1;
        // fun(v1,dp,idx-1);  // impt tt
        if(dp[idx]!=-1) rn dp[idx];
        int ans=INT_MIN;
        for(ll i=0;i<idx;++i) if(v1[i]<v1[idx]) ans=max(ans,fun(v1,dp,i));
        if(ans!=INT_MIN) ans+=1;
        else ans=1;
        fun(v1,dp,idx-1);
        rn dp[idx]=ans;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        ll n=nums.size();
        v<ll> dp(n,-1);
        fun(nums,dp,n-1);
        rn *max_element(dp.begin(),dp.end());
        
        // dp[0]=1;
        // for(ll i=1;i<n;++i)
        // {
        //     for(ll j=0;j<i;++j) 
        //         if(nums[i]>nums[j]) dp[i]=max(dp[i],dp[j]);
        //     dp[i]+=1;
        // }
        // rn *max_element(dp.begin(),dp.end());
    }  
        
    
};
