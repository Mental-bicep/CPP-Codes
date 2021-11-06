class Solution {
public:
    int arraySign(vector<int>& nums) {
        int cnt=0;
        for(auto ele:nums){
            if(ele==0) return 0;
            if(ele<0) ++cnt;
        }
        if(cnt&1) return -1;
        return 1;
    }
};
