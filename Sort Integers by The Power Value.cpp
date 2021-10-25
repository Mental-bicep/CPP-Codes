class Solution {
public:
    
    int fun(int n,vector<int>&dp){
        if(n==1) return 0;
        if(dp[n]!=-1) return dp[n];
        if(n%2==0) return dp[n]=fun(n/2,dp)+1;
        return dp[n]=fun(3*n+1,dp)+1;
    }
    int getKth(int lo, int hi, int k) {
        vector<int> dp(1000000,-1);
        vector<pair<int,int>> v1;
        for(int i=lo;i<=hi;++i) v1.push_back({i,fun(i,dp)});
        sort(v1.begin(),v1.end(),[](auto a,auto b){
            if(a.second==b.second) return a.first<b.first;
            return a.second<b.second;
        });
        return v1[k-1].first;
    }
};
