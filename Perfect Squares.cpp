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
    
    int fun(int n,v<ll> &dp)
    {
        if(n==1) rn dp[n]=1;
        if(dp[n]!=-1) rn dp[n];
        int ans=INT_MAX;
        for(int i=1;i*i<=n;++i) ans=min(ans,1+fun(n-i*i,dp));
        rn dp[n]=ans;
    }
    
    int numSquares(int n) {
        v<ll> dp(n+1,-1);
        dp[0]=0;
        auto ans=fun(n,dp);
        rn ans;
        // cout<<ans<<"\n";   
    }
};
