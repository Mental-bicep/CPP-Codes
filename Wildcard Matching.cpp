#define rn return 
#define v vector
class Solution {
public:
    
    bool fun(string &s1,string &p1,int sidx,int pidx,v<v<int>>&dp)
    {
        if(sidx==-1 and pidx==-1) return true;
        if( pidx==-1) return false;
        if(sidx==-1)
        {
            if(p1[pidx]=='*') return fun(s1,p1,sidx,pidx-1,dp);
            else return false;
        }
        if(dp[sidx][pidx]!=-1) return dp[sidx][pidx];
        if(p1[pidx]=='?') rn dp[sidx][pidx]= fun(s1,p1,sidx-1,pidx-1,dp);
        else if(p1[pidx]=='*') 
            return dp[sidx][pidx]= (fun(s1,p1,sidx-1,pidx-1,dp) or fun(s1,p1,sidx-1,pidx,dp) or fun(s1,p1,sidx,pidx-1,dp));
        else {
            if(s1[sidx]==p1[pidx]) return dp[sidx][pidx]= fun(s1,p1,sidx-1,pidx-1,dp);
            else return dp[sidx][pidx]= false;
        }
    }
    
    bool isMatch(string s1, string p1) {
        v<v<int>> dp(s1.size(),v<int>(p1.size(),-1));
        bool ans=fun(s1,p1,s1.size()-1,p1.size()-1,dp);
        return ans;
    }
};
