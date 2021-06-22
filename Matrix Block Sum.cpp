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
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        v<v<ll>> dp(mat.sz(),v<ll>(mat[0].sz())),ans(mat.sz(),v<ll>(mat[0].sz()));
        for(ll i=0;i<dp.sz();++i)
        {
            for(ll j=0;j<dp[0].sz();++j)
            {
                if(i==0 and j==0) dp[i][j]=mat[i][j];
                else if(j==0) dp[i][j]=dp[i-1][j]+mat[i][j];
                else if(i==0) dp[i][j]=dp[i][j-1]+mat[i][j];
                else dp[i][j]=dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1]+mat[i][j];
            }
        }
        
        for(ll i=0;i<dp.sz();++i)
        {
            for(ll j=0;j<dp[0].sz();++j)
            {
                ll tpi,tpj,bpi,bpj;
                if(i-k<0) tpi=0;
                else tpi=i-k;
                
                if(j-k<0) tpj=0;
                else tpj=j-k;
                
                if(i+k>=dp.sz()) bpi=dp.sz()-1;
                else bpi=i+k;
                
                if(j+k>=dp[0].sz()) bpj=dp[0].sz()-1;
                else bpj=j+k;
                
                ll mainbox,box1,box2,box3;
                mainbox=dp[bpi][bpj];
                
                if(tpj==0) box1=0;
                else box1=dp[bpi][tpj-1];
                
                if(tpi==0) box2=0;
                else box2=dp[tpi-1][bpj];
                
                if(tpi-1>=0 and tpj-1>=0) box3=dp[tpi-1][tpj-1];
                else box3=0;
                // if(i==0 and j==2){
                //     cout<<tpi<<" "<<tpj<<endl;
                //     cout<<bpi<<" "<<bpj<<"\n";
                //     cout<<mainbox<<" "<<box1<<" "<<box2<<" "<<box3<<"\n";
                // }
                ll res=mainbox-box1-box2+box3;
                ans[i][j]=res;
            }
        }
        rn ans;
        
    }
};
