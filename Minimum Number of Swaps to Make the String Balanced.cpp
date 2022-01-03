class Solution {
public:
    int minSwaps(string s1) {
        int cnt=0;
        int ans=INT_MIN;
        for(auto &ele:s1)
        {
            if(ele==']') ++cnt;
            else --cnt;
            ans=max(ans,cnt);
         }   
        return ceil((float)ans/2);
    }
};
