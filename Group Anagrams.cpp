class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp1;
        for(auto &ele:strs){
            string s1=ele;
            sort(s1.begin(),s1.end());
            mp1[s1].push_back(ele);
        }
        vector<vector<string>> v1;
        for(auto &ele:mp1) v1.push_back(ele.second);
        return v1;
    }
};
