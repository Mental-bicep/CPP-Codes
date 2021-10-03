#define umap unordered_map
#define f first
#define s second

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // if(trust.size()==0) return -1;
        if(n==1) return 1;
        umap<int,set<int>> mp1;
        for(int i=1;i<=n;++i) mp1[i];
        for(auto ele:trust) {mp1[ele[0]].insert(ele[1]);}
        vector<int> v1;
        for(auto ele:mp1) if(ele.second.size()==0) v1.push_back(ele.first);
        // if(v1.size()==1) return v1[0];
        for(auto ele:v1){
            bool flag=true;
            for(auto itms:mp1){
                if(itms.first==ele) continue;
                if(itms.second.find(ele)==itms.second.end()){
                    flag=false;
                    break;
                }
            }
            if(flag) return ele;
        }
        return -1;
    }
};
