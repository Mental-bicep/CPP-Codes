class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        for(int i=nums.size()-1;i>=0;--i)
        {
            if(st.size()==0 or nums[i]<st.top()) st.push(nums[i]);
            else if(nums[i]>st.top()) st.pop(),st.push(nums[i]);
        }
        vector<int> ans(nums.size());
        for(int i=nums.size()-1;i>=0;--i)
        {
            while(st.size()>0 and nums[i]>=st.top()) st.pop();
            if(st.size()==0) ans[i]=-1;
            else ans[i]=st.top();
            st.push(nums[i]);
        }
        return ans;
    }
};
