class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int>out(nums.size()),cnt(10,0);int i,n=nums.size();
        for(i=0;i<n;i++)
            cnt[nums[i]]++;
        for(i=1;i<10;i++)
            cnt[i]+=cnt[i-1];
        for(i=n-1;i>=0;i--)
        {
            out[cnt[nums[i]]-1]=nums[i];
            cnt[nums[i]]--;
        }
        for(i=0;i<n;i++)
            nums[i]=out[i];
        return;
    }
};
