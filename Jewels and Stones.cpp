class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
      unordered_map<char,bool> mp1;
        for(auto &ele:jewels) mp1[ele]=true;
        int cnt=0;
        for(auto &ele:stones) if(mp1[ele]) ++cnt;
        return cnt;
    }
};
