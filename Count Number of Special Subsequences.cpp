#define rn return 
#define ll long long
class Solution {
public:
    // ll power(ll a,ll b,ll &mod)
    // {
    //     if(b==0) rn 1;
    //     ll small=power(a,b/2,mod);
    //     small=(small%mod*small%mod)%mod;
    //     if(b&1) small=(small%mod*a%mod)%mod;
    //     rn small;
    // }
    int countSpecialSubsequences(vector<int>& v1) {
        // unordered_map<ll,ll> mp1;
        // for(auto &ele:v1) ++mp1[ele];
        // if(mp1.size()!=3) rn 0;
        //  // ll val= min({mp1[0],mp1[1],mp1[2]});
        // ll mod=1e9+7;
        // ll ans=1;
        // for(int i=0;i<3;++i)
        // {
        //     ll exp=power(2,mp1[i],mod);
        //     ans=(ans%mod*(exp-1)%mod)%mod;
        // }
        // rn ans;
        ll zero=0,one=0,two=0;
        ll mod=1e9+7;
        for(auto &ele:v1)
        {
            if(ele==0) zero=((zero%mod*2%mod)%mod+1)%mod;
            else if(ele==1) one=((one%mod*2)%mod+zero%mod)%mod;
            else two=((two%mod*2)%mod+one%mod)%mod;
        }
        rn two ;
    }
};
