class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int,int> mp1;
        for(auto &ele:nums) ++mp1[ele];
        vector<int> v2(105,0);
        v2[0]=0;
        for(int i=1;i<105;++i) v2[i]+=mp1[i-1]+v2[i-1];
        for(auto &ele:nums) ele=v2[ele];
        return nums;
    }
};
