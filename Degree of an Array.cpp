#define ll long long
#define mp make_pair
#define s second
#define f first
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<ll,ll> mp1;
        unordered_map<ll,ll> foc,loc;
        for(auto &ele:nums){ ++mp1[ele];
                               
        }
        for(int i=0;i<nums.size();++i){
            if(foc.find(nums[i])==foc.end()) foc[nums[i]]=i;
            loc[nums[i]]=i;
        }
        // pair<ll,ll> p1=mp(-1,-1);
        // vector<int> v1;
        ll ans=-1,res=LLONG_MAX;
        for(auto &ele:mp1)
            if(ele.s>ans)
                ans=ele.s;
        for(auto &ele:mp1) if(ele.s==ans) res=min(res,loc[ele.f]-foc[ele.f]+1);
        return res;
        
    }
};
