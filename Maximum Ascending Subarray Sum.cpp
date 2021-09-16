class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int temp=nums[0],ans=0;
        for(int i=1;i<nums.size();++i){
            if(nums[i]<=nums[i-1]){
                ans=max(ans,temp);
                temp=0;
            }
            temp+=nums[i];
        }
        ans=max(ans,temp);
        return ans;
    }
};
