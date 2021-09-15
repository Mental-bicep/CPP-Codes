class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp1;
        for(auto &ele:nums) ++mp1[ele];
        vector<pair<int,int>> v1;
        for(auto &ele:mp1) v1.push_back(ele);
        sort(v1.begin(),v1.end(),[](auto &a,auto &b){
            if(a.second==b.second) return a.first>b.first;
            return a.second<b.second;
            });
        nums.clear();
        for(auto &ele:v1) 
            for(int j=1;j<=ele.second;++j)
            nums.push_back(ele.first);
        return nums;
    }
};
