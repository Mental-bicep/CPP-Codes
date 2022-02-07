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
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        v<int> left(nums.sz()),right(nums.sz());
        int sum=0;
        for(int i=0;i<nums.sz();++i)
        {
            if(i<k) {
                sum+=nums[i];
                left[i]=sum;
            }
            else{
                sum+=nums[i]-nums[i-k];
                left[i]=max(sum,left[i-1]);
            }
        }
        sum=0;
        for(int i=nums.sz()-1;i>=0;--i)
        {
            if(i>=nums.sz()-k){
                sum+=nums[i];
                right[i]=sum;
            }
            else{
                sum+=nums[i]-nums[i+k];
                right[i]=max(sum,right[i+1]);
            }
        }
        v<int> psum(nums.sz());
        psum[0]=nums[0];
        fori(1,nums.sz()) psum[i]=psum[i-1]+nums[i];
        int ans=0; 
        int lidx,midx,eidx;
        int lsum,rsum;
        for(int i=k;i<=nums.sz()-2*k;++i){ 
            if(left[i-1]+right[i+k]+psum[i+k-1]-psum[i-1]>ans){ 
                midx=i;
                lsum=left[i-1];
                rsum=right[i+k];
                ans=left[i-1]+right[i+k]+psum[i+k-1]-psum[i-1];
            }
        }
        // cout<<ans<<"\n";
        for(int i=0;i+k-1<midx;++i) if(psum[i+k-1]-(i-1==-1?0:psum[i-1])==lsum){
            lidx=i;
            break;
        }

        for(int i=midx+k;i+k-1<=nums.sz()-1;++i) if(psum[i+k-1]-psum[i-1]==rsum) {
            eidx=i;
            break;
        } 
        v<int> res={lidx,midx,eidx};
        rn res;
    }
};

