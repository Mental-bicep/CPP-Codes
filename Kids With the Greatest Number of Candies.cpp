class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mxx=*max_element(candies.begin(),candies.end());
        vector<bool> v1;
        if(candies.size()==0) return v1;
        for(auto ele:candies) {
            if(ele+extraCandies>=mxx) v1.push_back(true);
            else v1.push_back(false);
        }
        return v1;
    }
};
