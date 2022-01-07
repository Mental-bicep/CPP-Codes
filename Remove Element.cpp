class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0,j=nums.size()-1;
        while(i<=j)
        {
            if(nums[i]==val){
                while(j>=0 and nums[j]==val) --j;
                if(j<i) break;
                else swap(nums[i++],nums[j--]); 
            } 
            else ++i;
        }
        // while(j>=0 and nums[j]==val) --j;
        return j+1;
    }
};
                   
                   
                   
