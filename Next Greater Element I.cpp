class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp1;
        stack<int> st;
        for(int i=nums2.size()-1;i>=0;--i)
        {
            while(st.size()>0 and nums2[i]>=st.top()) st.pop();
            if(st.size()==0) mp1[nums2[i]]=-1;
            else mp1[nums2[i]]=st.top();
            st.push(nums2[i]);
        }
        vector<int> ans;
        for(auto &ele:nums1) ans.push_back(mp1[ele]);
        return ans;
    }
};
