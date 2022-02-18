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
    
//     int fun(v<ll>&v1,ll sidx, ll eidx,umap<ll,ll>&mp1,v<v<ll>>&dp)
//     {   
//         // cout<<"inside function\n";
//         if(sidx>eidx) rn 0;
//         if(sidx==eidx) rn v1[sidx]*mp1[v1[sidx]];
//         if(dp[sidx][eidx]!=-1) rn dp[sidx][eidx];
//         ll ans=0;
//         for(ll i=sidx;i<=eidx;++i)
//         {
//             ll cans=v1[i]*mp1[v1[i]];
//             ll lans=0,rans=0;
//             if(i!=sidx){
//                 if(v1[i-1]!=v1[i]-1)
//                  lans=fun(v1,sidx,i-1,mp1,dp);
//                 else lans=fun(v1,sidx,i-2,mp1,dp);
//             } 
                
//             if(i!=eidx){
//                 if(v1[i+1]!=v1[i]+1)
//                  rans=fun(v1,i+1,eidx,mp1,dp);
//                 else rans=fun(v1,i+2,eidx,mp1,dp);
//             }
//             ans=max(ans,cans+lans+rans);
//         }
//         rn dp[sidx][eidx]=ans;
//     }
    
    int deleteAndEarn(vector<int>& nums) {
        // sort(rng(nums));
        // umap<ll,ll> mp1;
        // for(auto &ele:nums) ++mp1[ele];
        // auto it=unique(rng(nums));
        // nums.resize(it-nums.bn());
        // v<v<ll>> dp(nums.sz()+1,v<ll>(nums.sz()+1,-1));
        // int ans=fun(nums,0,nums.sz()-1,mp1,dp);
        // rn ans;
        int high=*mx(rng(nums));
        v<int> v1(high+1);
        for(auto &ele:nums) ++v1[ele];
        int inc=0,exc=0;
        for(int i=1;i<=high;++i)
        {
            int ninc=exc+i*v1[i];
            int nexc=max(inc,exc);
            inc=ninc;
            exc=nexc;
        }
        rn max(inc,exc);
        // v<int>
        
    }
};

