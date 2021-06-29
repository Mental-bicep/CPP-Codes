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
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        ll n=101;
        v<int> res(queries.sz());
        umap<ll,v<ll>> mp1;
        mp1[-1].resize(n);
        for(ll i=0;i<nums.sz();++i)
        {
            mp1[i]=mp1[i-1];
            mp1[i][nums[i]]+=1;
        }
        ll k=0;
        for(auto &ele:queries)
        {
            ll l=ele[0],r=ele[1];
            v<ll> v3;
            for(ll i=0;i<n;++i)
            {
                if((mp1[r][i]-mp1[l-1][i])!=0) v3.pb(i);
            }
            ll ans=INT_MAX;
            for(ll i=0;i<v3.sz()-1;++i) if(abs(v3[i]-v3[i+1])!=0) ans=min(ans,abs(v3[i]-v3[i+1]));
            // cout<<ans<<"\n";
            if(ans==INT_MAX) ans=-1;
            // res.pb(ans);
            res[k++]=ans;
        }
        rn res;
    }
};


