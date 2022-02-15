#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #define int long long
#define ll int
#define mod 1000000007
#define v vector
#define umap unordered_map
#define uset unordered_set
#define pq priority_queue
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define emp emplace
#define acc accumulate
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define bp __builtin_popcount
#define ins insert
#define mx max_element
#define mn min_element
#define bis back_inserter
#define tf transform
#define bn begin
#define pf push_front
#define ppf pop_front
#define p pair
#define cn count
#define cif count_if
#define fh for_each
#define rn return
#define rsg resize
#define rif remove_if
#define np next_permutation
#define pp prev_permutation
#define sz size
#define par partition
#define ub upper_bound
#define lb lower_bound
#define amp &
#define spar stable_partition
#define gt greater
#define rng(v1) v1.begin(), v1.end()
#define fori(m, n) for (auto i = m; i < n; i++)
#define forj(m, n) for (auto j = m; j < n; j++)
#define fork(m, n) for (auto k = m; k < n; k++)
using namespace std;
using namespace __gnu_pbds;

class Solution {
public:
    
    p<double,double> fun(int i,int j,v<v<p<double,double>>>&dp,double amt)
    {
        if(i==0 and j==0) {
            if(amt>1.0) {dp[i][j].f=1.0; dp[i][j].s=((double)amt-1)/2;}
            else {dp[i][j].f=amt;dp[i][j].s=0.0;}
            return dp[i][j];
    
        }
        if(dp[i][j]!=p<double,double>{-1,-1}) rn dp[i][j];
        if(j==0) {
            auto ans=fun(i-1,j,dp,amt);
            if(ans.s>1.0) {dp[i][j].f=1.0; dp[i][j].s=((double)ans.s-1)/2;}
            else {dp[i][j].f=ans.s;dp[i][j].s=0.0;}
        }
        else if(j==i) {
            auto ans=fun(i-1,j-1,dp,amt);
            if(ans.s>1.0) {dp[i][j].f=1.0; dp[i][j].s=((double)ans.s-1)/2;}
            else {dp[i][j].f=ans.s;dp[i][j].s=0.0;}
        } 
        else {
                auto ans1=fun(i-1,j-1,dp,amt) ;
                auto ans2=fun(i-1,j,dp,amt);
                double ans=ans1.s+ans2.s;
                if(ans>1.0) {dp[i][j].f=1.0;dp[i][j].s=((double)ans-1)/2;}
                else {dp[i][j].f=ans;dp[i][j].s=0.0; };
             }
        return dp[i][j];
    }
    
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<p<double,double>>> dp(query_row+1,v<p<double,double>>(query_row+1,{-1,-1}));
        auto ans=fun(query_row,query_glass,dp,poured);
        // cout<<"dp= \n";
        // for(auto &ele:dp)
        // {
        //     for(auto itms:ele) cout<<itms.f<<","<<itms.s<<"\t";
        //     cout<<"\n";
        // }
        rn ans.f;
        
        
    }
};
