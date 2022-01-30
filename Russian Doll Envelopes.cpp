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
    
    int fun(v<p<ll,ll>>&v1,v<ll> &dp,ll idx)   // width,height
    {   
        if(idx==0) rn dp[idx]=1;
        if(dp[idx]!=-1) rn dp[idx];
        int ans=0;
        for(int i=0;i<idx;++i)  if(v1[idx].s>v1[i].s and v1[idx].f>v1[i].f) ans=max(ans,fun(v1,dp,i));
        fun(v1,dp,idx-1);
        rn dp[idx]=ans+1;
    }
    
    int maxEnvelopes(vector<vector<int>>& env) {
        int n=env.sz();
        v<p<int,int>> v1(n);
        fori(0,n){
            v1[i].f=env[i][0];
            v1[i].s=env[i][1];
        }
        v<ll> dp(n,-1);
        sort(v1.begin(),v1.end(),[](auto &a,auto &b){
            if(a.f==b.f) rn a.s<b.s;
            rn a.f<b.f;
        });
        fun(v1,dp,n-1);
        rn *max_element(dp.begin(),dp.end());
    }
};
