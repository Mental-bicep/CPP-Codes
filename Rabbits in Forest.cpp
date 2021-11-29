#define umap unordered_map
#define rn return
#define ll int
#define s second
class Solution {
public:
    int numRabbits(vector<int>& v1) {
        umap<ll,ll> mp1;
    for(auto &ele:v1){
        if(mp1[ele]==0) mp1[ele]=ele;
        else --mp1[ele];
    }
    ll ans=v1.size();
    for(auto &ele:mp1) ans+=ele.s;
     rn ans;
    }
};
