class Solution {
public:
    vector<int> twoSum(vector<int>& v1, int target) {
        vector<int> res;
        for(int i=0,j=v1.size()-1;i<v1.size();){
            if(v1[i]+v1[j]==target) {
                res.push_back(i+1);
                res.push_back(j+1);
                return res;
            }
            else if(v1[i]+v1[j]>target) --j;
            else  ++i;
        }
        return res;
    }
};
