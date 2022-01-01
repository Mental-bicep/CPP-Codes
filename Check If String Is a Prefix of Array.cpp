#define rn return 
class Solution {
public:
    bool isPrefixString(string s1, vector<string>& words) {
        string res="";
        for(auto &ele:words)
        {
            res+=ele;
            if(s1.find(res)==string::npos) rn false;
            if(s1.size()==res.size()) rn true;
        }
        if(s1.size()==res.size())
        rn true;
        rn false;
    }
};
