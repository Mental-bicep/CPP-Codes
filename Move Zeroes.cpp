class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        stable_partition(nums.begin(),nums.end(),[](auto &a){return a!=0;});
        
    }
};
