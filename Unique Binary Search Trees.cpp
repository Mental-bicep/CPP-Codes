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
        if(n==0 or n==1) rn dp[n]=1;
        int ans=0;
        if(dp[n]!=-1) rn dp[n];
        for(int i=0,j=n-1;i<n;++i,--j) ans+=fun(i,dp) * fun(j,dp);
        rn dp[n]=ans;
    }
    
    int numTrees(int n) {
        v<ll> dp(n+1,-1);
        auto ans=fun(n,dp);
        rn ans;
        // cout<<ans<<"\n";   
    }
};
