#define rn return 
class Solution {
public:
    int maxProfit(vector<int>& v1) {
        if(v1.size()==0) rn 0;
        int mn=v1[0],ans=LLONG_MIN;
        for(auto & ele:v1)
        {
            mn=min(mn,ele);
            ans=max(ans,ele-mn);
            // mn=min(mn,ele);
        }
        rn ans;
    }
};
