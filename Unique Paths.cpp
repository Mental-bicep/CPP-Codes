#define ll long long 
class Solution {
public:
    
    ll fun(ll sr,ll sc, ll er,ll ec,vector<vector<ll>> &dp) 
    {
        if(sr<0 or sc<0 or sr>er or sc>ec) return 0;
        if(sr==er and sc==ec) return dp[sr][sc]=1;
        if(dp[sr][sc]!=-1) return dp[sr][sc];
        int ans=0;
        ans+=fun(sr,sc+1,er,ec,dp);
        ans+=fun(sr+1,sc,er,ec,dp);
        return dp[sr][sc]=ans;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<ll>> dp(m+1,vector<ll>(n+1,-1));
        auto ans=fun(0,0,m-1,n-1,dp);
        return ans;
    }
};
