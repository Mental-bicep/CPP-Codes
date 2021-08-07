#define umap unordered_map
#define rett return
class Solution {
public:
    umap<int,bool> mp1;
    bool divisorGame(int n) {
        if(n==1) rett false;
        if(mp1.find(n)!=mp1.end()) rett mp1[n];
        for(int i=1;i*i<=n;++i)
        {
            if(n%i==0 and divisorGame(n-i)==false) rett true;
            if(i!=1)
            {
                int num=n/i;
                if(n%num==0 and divisorGame(n-num)==false) rett true;
            }
        }
        rett mp1[n]=false;
    }
};
