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
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& v1) {
        v<ll> v2(v1.size());
        v2[0] = v1[0];
        for(ll i=1;i<v1.sz();++i)  v2[i]=v2[i-1] + v1[i];
        // for(auto &ele:v2) cout<<ele<<" ";
        // cout<<"\n";
        v<ll> res;
        for(ll i=0;i<v1.sz();++i)
        {  
            ll left=0,right=0;
            left= i*v1[i]- (i==0?0:v2[i-1]);
            right=(i==v1.sz()-1?0:v2.back()-v2[i]) - ((v1.sz()-1-i)*v1[i]);
            res.pb(left+right);
        }
        rn res;
    }
};
