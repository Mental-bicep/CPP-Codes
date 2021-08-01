class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1="",s2="";
        for(auto ele:word1) s1+=ele;
        for(auto ele:word2) s2+=ele;
        if(s1==s2) return true;
         return false;
    }
};
