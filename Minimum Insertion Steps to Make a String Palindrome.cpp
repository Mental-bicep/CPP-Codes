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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

class Solution {
public:
    ll fun(string &s1, ll i,ll j,v<v<ll>>&dp)
    {
        if(i==j) rn 0;
        if(i+1==j) rn s1[i]==s1[j]?0:1;
        if(dp[i][j]!=-1) rn dp[i][j];
        if(s1[i]==s1[j]) rn dp[i][j]=fun(s1,i+1,j-1,dp);
        ll ans1=1+fun(s1,i+1,j,dp);
        ll ans2=1+fun(s1,i,j-1,dp);
        rn dp[i][j]=min(ans1,ans2); 
    }

    int minInsertions(string s1) {
        if(s1.sz()==0) rn 0;
        v<v<ll>> dp(s1.sz(),v<ll>(s1.sz(),-1));
        auto ans=fun(s1,0,s1.sz()-1,dp);
        rn ans;
        // cout<<ans<<"\n";
    }
};
