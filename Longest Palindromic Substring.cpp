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
//     string fun(string &s1,int i,int j,v<v<ll>>&dp){
//         if(i>j) rn "";
//         if(i==j) rn string(1,s1[i]);
//         if(dp[i][j]!=-1) rn dp[i][j];
//         if(s1[i]==s1[j] and dp[i+1][j-1]) {
//             dp[i][j]=1;
//             rn j-i+1;
//         } 
//         dp[i][j]=0;
//         rn max(fun(s1,i+1,j,dp),fun(s1,i,j-1,dp));
    
// }
    
    void bottomup(string &s1,ll &si,ll &ei)
    {
        v<v<bool>> dp(s1.sz(),v<bool>(s1.sz()));
        for(ll g=0;g<s1.sz();++g)
        {
            for(ll i=0,j=g;j<s1.sz();++i,++j)
            {
                if(g==0) dp[i][j]=true;
                else if(g==1 and s1[i]==s1[j]) dp[i][j]=true;
                else{
                    if(s1[i]==s1[j] and dp[i+1][j-1]) dp[i][j]=true;
                }
                if(dp[i][j]) {
                    si=i;
                    ei=j;
                }
            }
        }
        return ;
    }
    
    string longestPalindrome(string s1) {
        ll i=-1,j=-1;
        bottomup(s1,i,j);
        return string(s1.bn()+i,s1.bn()+j+1);
    }
}; 
