class Solution {
public:
    string reverseVowels(string s) {
        int i=0,j=s.size()-1;
        string s1="aeiouAEIOU";
        while(i<j){
            while(i<s.size() and s1.find(s[i])==string::npos) ++i;
            while(j>=0 and s1.find(s[j])==string::npos) --j;
            if(i<j) swap(s[i++],s[j--]);
        }
        return s;
    }
};
