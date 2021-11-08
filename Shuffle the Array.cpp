class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> v(2*n);
        int k=0,i=0,j=n;
        while(i<n and j<2*n) {v[k++]=nums[i++];v[k++]=nums[j++];}
        return v;
        
    }
};
