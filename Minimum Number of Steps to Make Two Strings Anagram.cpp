#define umap unordered_map
#define ll long long
#define amp &
#define rn return 
#define ss second
class Solution {
public:
    int minSteps(string s, string t) {
        umap<char,ll> mp1;
        // for(auto & ele:t) ++mp1[ele];
        // for(auto amp ele:s) --mp1[ele];
        for(int i=0;i<s.size();++i)
        {
            ++mp1[t[i]];--mp1[s[i]];
        }
        int cnt=0;
        for(auto amp ele:mp1) if(ele.ss>0) cnt+=ele.ss;
        // for(auto amp ele:mp1) cout<<ele.first<<" "<<ele.ss<<"\n";
        rn cnt;
    }
};
