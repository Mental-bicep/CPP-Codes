class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> v1(nums.size());
        if(nums.size()==0) return v1;
        v1[0]=nums[0];
        for(int i=1;i<nums.size();++i) v1[i]=v1[i-1]+nums[i];
        return v1;
    }
};
