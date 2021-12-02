class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int cnt=0,sum=0;
        for(auto &ele:costs) {
            sum+=ele;
            if(sum>coins) break;
            ++cnt;
        }
        return cnt;
    }
};
