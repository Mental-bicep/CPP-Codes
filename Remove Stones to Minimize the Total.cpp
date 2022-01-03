#define rn return 
class Solution {
public:
    int minStoneSum(vector<int>& v1, int k) {
        priority_queue<int,vector<int>> pq(v1.begin(),v1.end());
        for(int i=1;i<=k;++i)
        {
            auto ele=pq.top();pq.pop();
            ele=ele-floor(ele/2);
            pq.push(ele);
        }
        int ans=0;
        while(!pq.empty())
        {
            auto ele=pq.top();
            pq.pop();
            ans+=ele;
        }
        rn ans;
    }
};
