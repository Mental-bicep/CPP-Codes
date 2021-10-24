class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        if(n==0) {
            vector<int> v;
            return v;
        }
        // if(n==1){
        //     vector<int> v;v.push_back(0);
        //     return v;
        // }
        unordered_map<int,bool> mp1;
        for(int i=0;i<n;++i) mp1[i];
        for(auto ele:edges) mp1[ele[1]]=true;
        vector<int> v1;
        for(auto ele:mp1) if(!mp1[ele.first]) v1.push_back(ele.first);
        return v1;
    }
};
