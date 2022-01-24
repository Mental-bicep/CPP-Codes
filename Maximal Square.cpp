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
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

class Solution {
public:
    
    ll fun(v<v<char>>&v1,v<v<ll>>&dp, ll r,ll c)
    {
        if(r<0 or c<0 ) rn 0;
        // if(r==0 or c==0) rn dp[r][c]=(v1[r][c]-'0'); // imp tt
        if(dp[r][c]!=-1) rn dp[r][c];  // single row and single column
        // if(v1[r][c]==0) rn dp[r][c]=0;   // imp tt
        int ans=INT_MAX;
        ans=min({ans,fun(v1,dp,r,c-1),fun(v1,dp,r-1,c),fun(v1,dp,r-1,c-1)});
        // cout<<"ans= "<<ans<<"\n";
        if(v1[r][c]=='0') ans=0;
        else ans+=1;
        rn dp[r][c]=ans;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        v<v<ll>> dp(matrix.size(),v<ll>(matrix[0].size(),-1));
        fun(matrix,dp,matrix.sz()-1,matrix[0].sz()-1);
        int ans=0;
        // for(auto &ele:dp)
        // {
        //     for(auto &itms:ele) cout<<itms<<" ";
        //     cout<<"\n";
        // }
        for(auto &ele:dp) for(auto &itms:ele) ans=max(ans,itms);
        // cout<<"ans= "<<ans<<"\n";
        return ans*ans;
    }
};
