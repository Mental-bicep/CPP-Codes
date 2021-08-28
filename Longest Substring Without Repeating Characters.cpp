class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        int cnt=0,ans=0;
        unordered_map<char,int> mp1;
        for(i=0;i<s.size();){
            if(mp1.find(s[i])==mp1.end()){
                mp1[s[i]]=i;
                ++i;
                ++cnt;
            }
            else{
                ans=max(ans,cnt);
                i=mp1[s[i]]+1;
                mp1.clear();
                cnt=0;
            }
        }
        ans=max(ans,cnt);
        return ans;
    }
};
