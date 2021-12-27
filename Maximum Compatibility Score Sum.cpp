#define rn return 
#define v vector
#define ll int
#define umap unordered_map
class Solution {
public:
    ll fun1(v<ll>&a,v<ll>&b)
    {
        ll ans=0;
            for(ll i=0;i<a.size();++i) if(a[i]==b[i]) ++ans;
        rn ans;
    }
    
    void fun2(v<v<ll>>&v1,v<v<ll>>&v2,umap<ll,bool>&mp1,ll i,ll csum,ll &osum)
    {
        if(i==v1.size())  {osum=max(osum,csum); rn;}
        for(ll j=0;j<v1.size();++j)
        {
            if(mp1[j]) continue;
            mp1[j]=true;
            ll ans=fun1(v1[i],v2[j]);
            fun2(v1,v2,mp1,i+1,csum+ans,osum);
            mp1[j]=false;
        }
             
    }
    
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        
        ll ans=0;
        unordered_map<ll,bool> mp1;
        fun2(students,mentors,mp1,0,0,ans);
        rn ans;
        
    }
};
