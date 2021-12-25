#define ll int
class Solution {
public:
    string maximumNumber(string s1, vector<int>& change) {
        for(ll i=0;i<s1.size();++i)
        {
            int ele=s1[i]-'0';
            bool flag=false;
            if(change[ele]>ele)
            {
                for(ll j=i;j<s1.size();++j)
                {
                    int ele=s1[j]-'0';
                    if(change[ele]>=ele) s1[j]=(change[ele]+'0');
                    else break;
                }
                flag=true;
            }
            if(flag) break;
        }
        return s1;
    }
};
