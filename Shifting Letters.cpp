#define mod 26
class Solution {
    
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        for(int i=shifts.size()-2;i>=0;i--) 
            shifts[i]=(shifts[i]%mod+shifts[i+1]%mod)%mod;
        for(int i=s.size()-1;i>=0;i--)
        {
            s[i]=(char)((s[i]-97+shifts[i])%26+97);
        }
        return s;
    }
};
