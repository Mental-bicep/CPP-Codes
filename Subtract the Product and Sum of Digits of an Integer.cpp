class Solution {
public:
    int subtractProductAndSum(int n) {
        string str=to_string(n);
        int sum=0,pro=1;
        for(auto ele:str){
            sum+=(ele-'0');
            pro*=(ele-'0');
        }
        return pro-sum;
    }
};
