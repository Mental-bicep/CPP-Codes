class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans=0;
        for(auto ele:accounts) 
        {
            int temp=accumulate(ele.begin(),ele.end(),0);
            ans=max(ans,temp);
        }
        return ans;
    }
};
