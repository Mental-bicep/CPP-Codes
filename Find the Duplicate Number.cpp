class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,bool> mp1;
        for(auto ele:nums){ if(mp1.find(ele)!=mp1.end()) return ele;else mp1[ele]=true;}
        return 1;
    }   
};
