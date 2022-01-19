class Solution {
public:
    
    double fun(double x,int n)
    {
        if(n==0) return 1;
        auto ans=fun(x,n/2);
        ans*=ans;
        if(n&1) ans*=x;
        return ans;
    }
    
    double myPow(double x, int n) {
        auto ans=fun(x,abs(n));
        if(n<0) return (float) 1/ans;
        return ans;
    }
};
