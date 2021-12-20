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
    int fun(string &s1,string &s2,int i,int j,v<v<ll>>&dp)
    {
        if(dp[i][j]!=-1) rn dp[i][j];
        if(i==s1.sz() and j==s2.sz()) rn 0;
        else if(i==s1.sz()) rn dp[i][j]=fun(s1,s2,i,j+1,dp)+s2[j];
        else if(j==s2.sz()) rn dp[i][j]=fun(s1,s2,i+1,j,dp)+s1[i];
        else if(s1[i]==s2[j]) rn dp[i][j]=fun(s1,s2,i+1,j+1,dp);
        else{
            ll op1=fun(s1,s2,i,j+1,dp)+s2[j];
            ll op2=fun(s1,s2,i+1,j,dp)+s1[i];
            rn dp[i][j]=min(op1,op2);
        }
    }
    int minimumDeleteSum(string s1, string s2) {
        v<v<int>> dp(s1.sz()+1,v<ll>(s2.sz()+1,-1));
        rn fun(s1,s2,0,0,dp);
    }
};
