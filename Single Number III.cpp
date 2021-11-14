#define ll long long
class Solution {
public:
    vector<int> singleNumber(vector<int>& v1) {
                
    ll res = 0;
    for (auto &ele : v1)
        res ^= ele;
    ll bit = 0;
    while (res)
    {
        if (res & 1)
            break;
        ++bit;
        res = res >> 1;
    }
    int mask = (1 << bit);
    int num1 = 0, num2 = 0;
    for (auto &ele : v1)
    {
        if (ele & mask)
            num1 ^= ele;
        else
            num2 ^= ele;
    }
        vector<int> v2={min(num1,num2),max(num1,num2)};
        return v2;
         
    }
};
