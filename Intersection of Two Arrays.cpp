class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int arr[10000]={0};
        vector<int> v;
        int i,s1=nums1.size(),s2=nums2.size();
            for(i=0;i<s1;i++)
                arr[nums1[i]]++;
        for(i=0;i<s2;i++)
            if(arr[nums2[i]]>0){
                v.push_back(nums2[i]);
                arr[nums2[i]]=0;
            }
        return v;
    }
};
