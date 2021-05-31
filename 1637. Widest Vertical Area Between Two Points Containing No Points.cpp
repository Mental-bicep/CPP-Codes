#define rn return 
#define sz size 
#define ll int 
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& v1) {
        sort(v1.begin(),v1.end(),[](auto &a,auto &b){
            if(a[0]==b[0]) rn a[1]<b[1];
            rn a[0]<b[0];
        });
        ll ans=0;
        for(ll i=0;i<v1.sz()-1;++i) ans=max(ans,abs(v1[i][0]-v1[i+1][0]));
        rn ans;
    }
};
