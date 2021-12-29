#define ll int
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // cout<<"inside function\n";
        vector<int> v1(arr.size()); v1[0]=arr[0];
        for(int i=1;i<arr.size();++i) v1[i]=(v1[i-1]^arr[i]);
        vector<int> res(queries.size());
        int k=0;
        for(auto &ele:queries)
        {   int lidx=ele[0];
            // cout<<"inside loop\n";
            ll ans1=lidx==0? 0:v1[lidx-1];
            ll ans2=v1[ele[1]];
            
            res[k++]=(ans1^ans2);
        }
        return res;
    }
};
