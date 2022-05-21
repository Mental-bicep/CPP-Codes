class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int si=0,ei=nums.size()-1;
        while(si<=ei)
        {
            int mid=si+(ei-si)/2;
            if(mid==0)
            {
                if(nums[mid]>nums[mid+1]) return mid;
                else si=mid+1;
            }
            else if(mid==nums.size()-1)
            {
                if(nums[mid]>nums[mid-1]) return mid;
                else ei=mid-1;
            }
            else if(nums[mid]>nums[mid-1] and nums[mid]>nums[mid+1]) return mid;
            else if(nums[mid-1]>nums[mid]) ei=mid-1;
            else if(nums[mid+1]>nums[mid]) si=mid+1;
            // if(nums[mid])
        }
        cout<<"returning -1\n";
        return 0;
        // return -1;
    }
};
