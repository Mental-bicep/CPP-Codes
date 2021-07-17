class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       if(nums.size()==0)
           return 0;
        int i,k;
        for(i=1,k=0;i<nums.size();i++)
        {  if (nums[i]!=nums[i-1])
                nums[k++]=nums[i-1];
        }
            //if(v[i-1]!=v[j-1])
            nums[k]=nums[i-1];
        return (k+1);
}
};
