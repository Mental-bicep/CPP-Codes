class Solution {
public:
    
    int fun(int n,vector<int>&dp)
    {
        if(n==0 or n==1) return 0;
        if(dp[n]!=-1) return dp[n];
		dp[n]=n;

		for(int i=2;i*i<=n;++i)
		{
		  
		    if(n%i==0)
		    {
		        int ans=fun(n/i,dp);
		        dp[n]=min(dp[n],ans+(i) );
		    }
		}

		return dp[n];
    }
    
    int minSteps(int n) {
        vector<int> dp(n+1,-1);
        return fun(n,dp);
    }
};
