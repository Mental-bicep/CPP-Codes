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
    v<ll> dx,dy;
    void fun(v<v<ll>> &g1,v<v<ll>>&g2, ll x,ll y,v<v<ll>>&vis,bool &flag)
    {
        if(x<0 or y<0 or x>=g2.sz() or y>=g2[0].sz()) rn ;
        if(vis[x][y] or g2[x][y]==0 )  rn;
        vis[x][y]=1;
        if(g1[x][y]==0) flag=false;
        for(ll i=0;i<4;++i) fun(g1,g2,x+dx[i],y+dy[i],vis,flag);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        dx=v<ll>{-1,0,1,0};
        dy=v<ll>{0,-1,0,1};
        ll cnt=0;
        ll row=grid1.sz(),col=grid1[0].sz();
        v<v<ll>> vis(row,v<ll>(col,false));
        for(ll i=0;i<grid1.sz();++i)
        {
            for(ll j=0;j<grid1[0].sz();++j)
                if(grid2[i][j]==1 and vis[i][j]==0)
                {
                    bool flag=true;
                    fun(grid1,grid2,i,j,vis,flag);
                    if(flag) ++cnt;
                }
        }
        rn cnt;
    }
};
