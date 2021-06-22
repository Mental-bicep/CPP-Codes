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
    int countBattleships(vector<vector<char>>& board) {
        v<v<bool>> v1(board.sz(),v<bool>(board[0].sz(),false));
        ll ans=0;
        for(ll i=0;i<board.sz();++i)
        {
            for(ll j=0;j<board[0].sz();++j)
            {
                if(board[i][j]=='X')
                {
                    if(v1[i][j]==false) ++ans;
                    if(j+1<board[0].sz()) v1[i][j+1]=true;
                    if(i+1<board.sz()) v1[i+1][j]=true;
                }
            }
        }
        rn ans;
    }
};
