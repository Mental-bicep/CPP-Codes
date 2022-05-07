class Solution {
public:
    string addSpaces(string s1, vector<int>& spaces) {
        int i=0,j=0;
        unordered_map<int,bool> mp1;
        for(auto &ele:spaces) mp1[ele]=true;
        string res;
        while(j<s1.size())
        {
            if(mp1.find(j)!=mp1.end())
                res.push_back(' ');
            res.push_back(s1[j++]);
            // ++i;
        }
        return res;
    }
    
};
