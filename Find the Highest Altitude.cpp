class Solution {
public:
    int largestAltitude(vector<int>& v1) {
        int ans=0;
        int sum=0;
        for(int i=0;i<v1.size();++i)
        {
            sum+=v1[i];
            ans=max(ans,sum);
        }
        return ans;
    }
};
