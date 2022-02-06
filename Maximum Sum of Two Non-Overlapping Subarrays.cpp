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
    v<int> ltr(v<int>&v1, int len)
    {
        v<int>res(v1.sz());
        int sum=0;
        for(int i=0;i<v1.sz();++i)
        {
            if(i<len){
                sum+=v1[i];
                res[i]=sum;
            } 
            else{
                sum+=v1[i]-v1[i-len];
                res[i]=max(sum,res[i-1]);
            }
        } 
        rn res;
    }

    v<int> rtl(v<int> &v1, int len)
    {
       int sum=0;
       v<int> res(v1.sz());
        for(int i=v1.sz()-1;i>=0;--i)
        {
            if(i>=v1.sz()-len){
                sum+=v1[i];
                res[i]=sum;
            }
            else{
                sum+=v1[i]-v1[i+len];
                res[i]=max(res[i+1],sum);
            }
        }
        rn res;
    }

      int maxSumTwoNoOverlap(vector<int>& nums, int flen, int slen) {
        v<int>dp1=ltr(nums,flen);
        v<int>dp2=rtl(nums,slen);
        int ans=0;
        for(int i=flen-1;i<=nums.sz()-slen-1;++i) ans=max(ans,dp1[i]+dp2[i+1]);
        dp1=ltr(nums,slen);
        dp2=rtl(nums,flen);
        for(int i=slen-1;i<=nums.sz()-flen-1;++i) ans=max(ans,dp1[i]+dp2[i+1]);
        rn ans;
    }   
};
