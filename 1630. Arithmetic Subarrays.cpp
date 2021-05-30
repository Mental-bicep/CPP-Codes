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
    vector<bool> checkArithmeticSubarrays(vector<int>& v1, vector<int>& l, vector<int>& r) {
        v<bool> res;
    fori(0,l.sz()){
        ll left=l[i];
        ll right=r[i];
        if(left==right){
            res.pb(false);
            continue;
        }
        ll mxx=INT_MIN;
        ll mnn=INT_MAX;
        umap<ll,bool> mp1;
        forj(left,right+1){
            mnn=min(v1[j],mnn);
            mxx=max(v1[j],mxx);
            mp1[v1[j]]=true;
        }
        float f=(float)(mxx-mnn)/(right-left);
        // ll d=(mxx-mnn)/(right-left);
        ll d=f;
        if(d-f!=0){     
            res.pb(false);    // imp tt
            continue;
        }
        ll n=right-left+1;
        bool flag=true;
        for(ll j=1;j<=n;++j){
            ll ele=mnn+(j-1)*d;
            if(mp1[ele]==false) {
                flag=false;
                break;
            }
        }
        res.pb(flag);
    }
        rn res;
    }
};
