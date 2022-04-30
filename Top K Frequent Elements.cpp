class comp{
  public:
    bool operator ()(pair<int,int> &a,pair<int,int> &b)
    {
        return a.second>b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue< pair<int,int>,vector<pair<int,int>>,comp > pq;
        unordered_map<int,int> mp1;
        for(auto &ele:nums) ++mp1[ele];
        for(auto &ele:mp1) {
            pq.push(ele);
            if(pq.size()>k) pq.pop();                           
        }
        vector<int> res;
        while(pq.size()>0)
        {
            auto ele=pq.top();pq.pop();
            res.push_back(ele.first);
        }
        return res;
        
    }
};
