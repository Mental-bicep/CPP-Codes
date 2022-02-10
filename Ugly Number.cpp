#define ll long long
class Solution {
public:
  // vector<int> fun(int n)
    // {
    //     vector<int> v1;
    //     for(int i=2;(ll)i*i<=(ll)n;++i)
    //     {
    //         if(n%i==0)
    //         {
    //             v1.push_back(i);
    //             while(n%i==0) n=n/i;
    //         }
    //     }
    //     if(n!=1) v1.push_back(n);
    //     return v1;
    // }
    bool isUgly(int n) {
        // auto ans=fun((n));
        // for(auto &ele:ans) if(ele!=2 and ele!=3 and ele!=5) return false;
        // return true;
        
        // method-2
        if(n<=0) return false;
        vector<int> v1={2,3,5};
        for(auto &ele:v1)
            while(n%ele==0) n=n/ele;
        return n==1;
    }
};
