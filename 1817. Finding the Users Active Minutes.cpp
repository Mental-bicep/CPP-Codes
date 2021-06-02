class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> res(k,0);
        unordered_map<int,set<int>> mp1;
        for(auto &ele:logs) mp1[ele[0]].insert(ele[1]);
        unordered_map<int,int> mp2;
        for(auto &ele:mp1) mp2[ele.second.size()]++;
        for(int i=0;i<k;++i) res[i] = mp2[i+1];
        return res;
    }
};
