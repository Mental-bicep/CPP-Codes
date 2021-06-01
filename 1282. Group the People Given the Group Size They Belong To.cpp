#define pb push_back
#define umap unordered_map
#define sz size
#define v vector
#define ll int

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& v1) {
        v<v<int>> res;
        umap<int,v<int>> mp1;
        for(ll i=0;i<v1.sz();++i) {
            mp1[v1[i]].pb(i);
            if(mp1[v1[i]].sz()==v1[i]){
                res.pb(mp1[v1[i]]);
                mp1[v1[i]].clear();
            }
        }
        sort(res.begin(),res.end(),[](auto &a,auto &b){ return a.sz()<b.sz();});
        return res;
        
    }
};
