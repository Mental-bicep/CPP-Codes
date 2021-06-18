class Solution {
public:
    bool fun(int x,int y,int x1,int y1,int r){
        int op1=pow(x-x1,2);
        int op2=pow(y-y1,2);
        r=r*r;
        if(op1+op2<=r) return true;
        return false;
    }
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int>res;
        for(auto &ele:queries){
            int cnt=0;
            for(auto &itms:points) if(fun(ele[0],ele[1],itms[0],itms[1],ele[2])) ++cnt;
            res.push_back(cnt);
        }
        return res;
    }
};
