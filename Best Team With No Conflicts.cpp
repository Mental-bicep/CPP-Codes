#include<bits/stdc++.h>
using namespace std;
#define ll int 
// #define int long long 
#define v vector
#define rn return 
#define sz size
#define f first
#define s second
#define fori(a,b) for(auto i=a;i<b;++i)
class Solution {
public:
    
    int fun(v<pair<int,int>> &v1,v<ll> &dp,int idx)  /// score,age
    {
        if(idx==0) rn dp[idx]= (v1[idx].f >= 0 ? v1[idx].f:0);
        if(dp[idx]!=-1) rn dp[idx];
        int ans=0;
        for(int i=0;i<idx;++i) if(v1[i].f<=v1[idx].f) ans=max(ans,fun(v1,dp,i));
        ans+=v1[idx].f;
        fun(v1,dp,idx-1);
        rn dp[idx]=ans;
    }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        v<pair<int,int>> v1(scores.sz());  // score,age
        fori(0,ages.sz()) {
            v1[i].f=scores[i];
            v1[i].s=ages[i];
        }
        sort(v1.begin(),v1.end(),[](auto &a,auto &b){
            if(a.s==b.s) rn a.f<b.f;
            rn a.s<b.s;
        });
        v<ll> dp(ages.size(),-1);
        fun(v1,dp,ages.sz()-1);
        rn *max_element(dp.begin(),dp.end());
        
    }
};
