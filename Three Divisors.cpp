#define rn return 
class Solution {
public:
    bool isprime(int n)
    {    
        if(n==1) rn false;
        if(n==2) rn true;
        if(n%2==0) rn false;
        for(int i=2;i*i<=n;++i) if(n%i==0 ) rn false;
        rn true;
    }
    bool isThree(int n) {
        int m=sqrt(n);
        if(isprime(m) and m*m==n) rn true;
        rn false;
    }
};
