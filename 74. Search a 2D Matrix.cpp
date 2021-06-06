#define rng(x) x.begin(),x.end()
#define sz size
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v1, int val) {
        bool ans = false;
    for (auto &ele : v1)
    {
        if (ele[ele.sz() - 1] >= val)
        {
            ans = binary_search(rng(ele), val);
            break;
        }
    }
        return ans;
    // if (ans)
    //     cout << "true\n";
    // else
    //     cout << "false\n";
    // return 0;
    }
};
