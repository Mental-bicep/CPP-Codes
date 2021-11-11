#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #define int long long
#define ll long long
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& v1, vector<string>& v2) {
        umap<char, ll> mp1;
    char ch = 'a';
    fori(0, 26) mp1[ch++] = i;
    umap<char, vector<int>> mp2;
    for (auto ele : v1)
    {
        int msk = 0;
        for (auto itms : ele)
            msk = msk | (1 << mp1[itms]);
        set<char> st;
        for (auto &itms : ele)
            if (st.find(itms) == st.end())
            {
                st.insert(itms);
                mp2[itms].pb(msk);
            }
    }
        vector<int> ans;
    for (auto &ele : v2)
    {
        int msk = 0;
        for (auto &itms : ele)
            msk = msk | (1 << mp1[itms]);
        int cnt = 0;
        for (auto &itms : mp2[ele[0]])
            if ((itms & msk) == itms)
                ++cnt;
        // cout << ele << " -> " << cnt << "\n";
        ans.pb(cnt);
    }   
        return ans;
    }
};
