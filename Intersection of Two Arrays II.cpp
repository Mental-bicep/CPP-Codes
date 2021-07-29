class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int s1=nums1.size(),s2=nums2.size(),i=0,j=0;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> v;
        while(i<s1 && j<s2)
        {
            if(nums1[i]<nums2[j])
                i++;
            else if(nums1[i]>nums2[j])
                j++;
            else{
                v.push_back(nums1[i++]);
                j++;
            }
                
        }
    return v;
    }
};
