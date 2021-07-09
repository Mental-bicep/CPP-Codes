class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> mp1;
        for(auto &ele:nums) ++mp1[ele]; 
        int ans=0;
        for(auto &ele:mp1) ans+=((ele.second-1)*ele.second)/2;
        return ans;
    }
};
