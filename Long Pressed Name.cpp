#define rn return 
class Solution {
public:
    bool isLongPressedName(string s1, string s2) {
        set<char> st1(s1.begin(),s1.end());
        set<char> st2(s2.begin(),s2.end());
        if(st1!=st2) rn false;
        int i=0,j=0;
        for(;i<s1.size() and j<s2.size();){
            if(s1[i]!=s2[j]) rn false;
            int i1=i+1,j1=j+1;
            while(i1<s1.size() and s1[i1-1]==s1[i1]) ++i1;
            while(j1<s2.size() and s2[j1-1]==s2[j1]) ++j1;
            if(i1-i>j1-j) rn false;
            i=i1;
            j=j1;
        }
        if((i==s1.size() and j!=s2.size()) or (i!=s1.size() and j==s2.size())) rn false;
        rn true;
        
    }
};
