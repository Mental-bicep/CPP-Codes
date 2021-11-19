class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string s1;
        s1.resize(s.size());
        for(int i=0;i<s.size();++i)
            s1[indices[i]]=s[i];
        
        return s1;
    }
};
