#define umap unordered_map
#define sz size 
#define rn return 
#define ll int 
class Solution {
public:
    int lengthOfLongestSubstring(string s1) {
        ll i=0,j=0,ans=0;
    umap<char,ll> mp1;
    while(true){
        bool flag=false;
        for(;i<s1.sz();i++){
            if(mp1[s1[i]]!=0) break;
            ++mp1[s1[i]];
            flag=true;
        }
        ans=max(ans,i-j);
        for(;j<i;++j){
            if(mp1[s1[i]]==0) break;
            if(mp1[s1[j]]==1) mp1.erase(s1[j]);
            else --mp1[s1[j]];
        }
        if(flag==false) break;
    }
     rn ans;
    }
};
