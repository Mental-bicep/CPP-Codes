class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char,bool> mp1;
        for(auto ele:sentence) mp1[ele]=true;
        bool flag=true;
        for(char ch='a';ch<='z';++ch) if(mp1[ch]==false){flag=false;break;}
        return flag;
    }
};
