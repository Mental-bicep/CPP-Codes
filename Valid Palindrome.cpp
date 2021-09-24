class Solution {
public:
    bool isPalindrome(string s) {
        // string s1="";
        // for(auto ele:s) if(isalpha(ele) or isdigit(ele)) s1.push_back(tolower(ele));
        // s=s1;
        // reverse(s.begin(),s.end());
        // return s1==s;
        int i=0,j=s.size()-1;
        bool flag=true;
        while(i<j){
            while(i<s.size() and isalnum(s[i])==false) ++i;
            while(j>=0 and isalnum(s[j])==false) --j;
            if(i<j){
                if(tolower(s[i])!=tolower(s[j])){
                    flag=false;break;
                }
                ++i;--j;
            }
            
        }
        return flag;
    }
};
