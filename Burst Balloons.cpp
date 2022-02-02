#include<bits/stdc++.h>
using namespace std;
#define ll int
// #define int long long 
#define v vector
#define rn return 
#define sz size
#define p pair
#define fori(a,b) for(auto i=a;i<b;++i)
#define f first
#define s second

class Solution {
public:
    
    ll fun(v<ll> &v1,v<v<ll>> &dp,ll sidx,ll eidx)
    {
        // if(sidx<eidx) rn 0;
        if(sidx==eidx)
        {
            ll lans= sidx==0? 1 : v1[sidx-1];
            ll rans= eidx==v1.sz()-1? 1: v1[eidx+1];
            rn v1[sidx]*lans*rans;
        }
        if(dp[sidx][eidx]!=-1) rn dp[sidx][eidx];
        int ans=LLONG_MIN;
        for(ll k=sidx;k<=eidx;++k)
        {
            ll lans= (k==sidx?0:fun(v1,dp,sidx,k-1));
            ll rans= (k==eidx? 0:fun(v1,dp,k+1,eidx));
            ans=max(ans, lans+rans+v1[k]* (sidx==0?1:v1[sidx-1]) * (eidx==v1.sz()-1 ?1:v1[eidx+1]) );
        }
        rn dp[sidx][eidx]=ans;
    }
    
    int maxCoins(vector<int>& nums) {
        int n=nums.sz();
        v<v<ll>> dp(n,v<ll>(n,-1));
        auto ans=fun(nums,dp,0,n-1);
        rn ans;
        // cout<<ans<<"\n";
    }
};
