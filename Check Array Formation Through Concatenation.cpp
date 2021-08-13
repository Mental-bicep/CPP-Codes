#define rn return 
#define rng(x) x.begin(),x.end()
#define v vector
#define umap unordered_map
#define pb push_back
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        
        umap<int,v<int>> mp1;
        v<int> v1;
        for(auto ele:pieces) mp1[ele[0]]=ele;
        for(auto ele:arr)
        {
            
            if(mp1.find(ele)!=mp1.end())    
            for(auto items:mp1[ele]) v1.pb(items);
     
        }
        rn v1==arr;
    }
};
