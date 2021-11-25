#define umap unordered_map
#define fori(m,n) for(auto i=m;i<n;++i)
#define rn return 
#define ll int
template<typename t>
class dsu
{
public:
    umap<t, t> parent, rank;
    ll total_comp;
    dsu(ll n)
    {
        total_comp = n;
        fori(1, n+1)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    t get_parent(t x)
    {
        if (x == parent[x])
            rn x;
        rn parent[x] = get_parent(parent[x]);
    }
    void unite(t x, t y)
    {
        auto parx = get_parent(x);
        auto pary = get_parent(y);
        if (parx != pary)
        {
            if (rank[parx] < rank[pary])
            {
                parent[parx] = pary;
                rank[pary] += rank[parx];
            }
            else
            {
                parent[pary] = parx;
                rank[parx] += rank[pary];
            }
            --total_comp;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        dsu<int> g(edges.size());
        for(auto &ele:edges){
            if(g.get_parent(ele[0])==g.get_parent(ele[1])) return ele;
            else g.unite(ele[0],ele[1]);
        }
        rn vector<int>{-1,-1};
    }
};
