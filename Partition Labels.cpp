class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        unordered_map<char,int> mp1;
        for(auto ele:s){
            if(mp1.find(ele)==mp1.end()) mp1[ele]=s.find_last_of(ele);
        }
        int start=0,end=0;
        vector<int> v1;
        for(int i=0;i<s.size();++i){
            end=max(end,mp1[s[i]]);
            if(i==end) {v1.push_back(end-start+1);
                        start=i+1;end=0;
                       }
        }
        return v1;
    }
};
