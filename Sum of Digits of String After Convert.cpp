#define ll int
class Solution {
public:
    int getLucky(string s1, int k) {
        string res="";
        for(auto &ele:s1) res+=to_string((int)(ele)-97+1);
        for(ll i=1;i<=k;++i)
        {
            ll sum=0;
            for(auto &ele:res) sum+=(ele-'0');
            res=to_string(sum);
        }
        return stoi(res);
    }
};
