class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2)
            return 0;
        int mx=0,sz=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=1;i<sz;i++)
            if(abs(nums[i]-nums[i-1])>mx)
                mx=abs(nums[i]-nums[i-1]);
        return mx;
    }
};
