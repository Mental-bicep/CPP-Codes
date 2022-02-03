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
    
    ll fun(v<ll> &v1,v<v<ll>> &dp, ll sidx, ll eidx)
    {
        if(eidx-sidx+1<=2) rn dp[sidx][eidx]=0;
        if(sidx+2==eidx) rn dp[sidx][eidx]=v1[sidx] * v1[eidx] * v1[sidx+1];
        if(dp[sidx][eidx]!=-1) rn dp[sidx][eidx];
        ll ans=INT_MAX;
        for(int k=sidx+1;k<eidx;++k)
        {
            int lans=fun(v1,dp,sidx,k);
            ll rans=fun(v1,dp,k,eidx);
            ans=min(ans, lans+rans+ v1[sidx] * v1[eidx] * v1[k]);

        }
        rn dp[sidx][eidx]=ans;
    }
    
    int minScoreTriangulation(vector<int>& values) {
        int n=values.sz();
        v<v<ll>> dp(n,v<ll>(n,-1)) ;
        auto ans=fun(values,dp,0,n-1);
        rn ans;
        // cout<<ans<<"\n";
    }
};
