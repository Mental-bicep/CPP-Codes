#define ll long long 
class Solution {
public:
    bool isPerfectSquare(int num) {
        ll s=1,e=num;
        while(s<=e)
        {
            ll mid=(s+e)/2;
            if(mid*mid==num) return true;
            else if(mid*mid>num) e=mid-1;
            else s=mid+1;
        }
        return false;
    }
};
