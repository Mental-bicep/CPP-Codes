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
class Solution {
public:
    ll fun(v<ll> &v1,ll i,ll j,v<v<ll>>&dp)
    {
        if(i>j) rn 0;
        if(dp[i][j]!=-1) rn dp[i][j];
        if(i==j) rn v1[i];
        ll op1=v1[i]+min(fun(v1,i+1,j-1,dp),fun(v1,i+2,j,dp));
        ll op2=v1[j]+min(fun(v1,i+1,j-1,dp),fun(v1,i,j-2,dp));
        rn dp[i][j]=max(op1,op2);
        
    }
    bool PredictTheWinner(vector<int>& nums) {
        ll sum=acc(rng(nums),0);
        v<v<ll>> dp(nums.sz()+2,v<ll>(nums.sz()+2,-1));
        ll ans=fun(nums,0,nums.sz()-1,dp);
        if(sum-ans>ans) rn false;
        rn true;
    }
};
