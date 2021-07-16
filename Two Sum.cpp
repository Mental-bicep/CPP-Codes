class Solution {
public:
    vector <int>v1;
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j;
        
            for(i=0;i<nums.size()-1;i++)
            {
                for(j=i+1;j<nums.size();j++)
                {
                    if(nums[i]+nums[j]==target)
                    {
                        v1.push_back(i);
                        v1.push_back(j);
                        return v1;
                    }
                }
            }
     return v1;
    }
};
