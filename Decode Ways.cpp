#define ll int
#define v vector
class Solution {
public:
    int fun(string &s1,int idx,v<int>&dp)
    {
        if(idx==s1.size()) return 1;
        if(dp[idx]!=-1) return dp[idx];
        if(s1[idx]=='0') return 0;
        int ans=0;
        if(idx+1<=s1.size())
        ans+=fun(s1,idx+1,dp);
        if(idx+2<=s1.size() and stoi(s1.substr(idx,2))<=26 )
        ans+=fun(s1,idx+2,dp);
        return dp[idx]=ans;
    }
    
    int numDecodings(string s1) {
        vector<int> dp(s1.size(),-1);
        int ans=fun(s1,0,dp);
        return ans;
         
    }
};
