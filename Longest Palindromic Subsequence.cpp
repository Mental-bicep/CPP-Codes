#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #define int long long
// #define ll int
#define ll long long
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
    ll fun(string &s1,ll i,ll j,v<v<ll>>&dp)
    {
        if(i>j) rn 0;
        if(i==j) rn 1;
        if(j==i+1) {
            if(s1[i]==s1[j]) rn 2;
            rn 1;
        }
        if(dp[i][j]!=-1) rn dp[i][j];
        if(s1[i]==s1[j]) rn dp[i][j]=2+fun(s1,i+1,j-1,dp);
        else rn dp[i][j]=max(fun(s1,i+1,j,dp),fun(s1,i,j-1,dp));
    }
    int longestPalindromeSubseq(string s1) {
        v<v<ll>> dp(s1.sz()+2,v<ll>(s1.sz()+2,-1));
        ll ans=fun(s1,0,s1.sz()-1,dp);
        rn ans;
    }
};
