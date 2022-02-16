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
    
    int fun(int idx,v<int>&v1,int jump,umap<int,bool>&mp1,map<pair<int,int>,int>&dp)
    {   
        if(idx==v1.back()) return 1;
        if(idx==0) return fun(idx+1,v1,1,mp1,dp);
        if(!mp1[idx]) rn 0;
        if(dp.find(mp(idx,jump))!=dp.end()) rn dp[mp(idx,jump)];
        int ans=0;
        if(jump-1>0 and idx+jump-1<=v1.back()) ans=fun(idx+jump-1,v1,jump-1,mp1,dp);
        if(ans) rn dp[mp(idx,jump)]=ans;
        if(jump>0 and idx+jump<=v1.back()) ans=fun(idx+jump,v1,jump,mp1,dp);
        if(ans) rn dp[mp(idx,jump)]=ans;
        if(jump+1 and idx+jump+1<=v1.back()) ans=fun(idx+jump+1,v1,jump+1,mp1,dp);
        rn dp[mp(idx,jump)]=ans;
    }
    
    bool canCross(vector<int>& stones) {
         umap<int,bool> mp1;
        map<pair<int,int>,int> dp;
        // v<v<int>> dp(stones.sz()+1,v<int>())
        for(auto &ele:stones) mp1[ele]=true;
        auto ans=fun(0,stones,0,mp1,dp);
        return ans==1; 
    }
};
