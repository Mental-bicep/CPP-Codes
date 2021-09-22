#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // vector<int> v1;
        copy(nums2.begin(),nums2.end(),nums1.begin()+m); 
        // std::merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),back_inserter(v1));
        // return v1;
        inplace_merge(nums1.begin(),nums1.begin()+m,nums1.end());
    }
};
