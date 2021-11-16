class Solution {
public:
    unordered_map<int,int> mp1;
    int fun(int n){
        if(n==0) return n;
        if(mp1.find(n)!=mp1.end()) return mp1[n];
        if(n&1)  return mp1[n]=fun(n-1)+1;
        else return mp1[n]=fun(n/2)+1;
    }
    int numberOfSteps(int num) {
        int ans=fun(num);
        return ans;
    }
};
