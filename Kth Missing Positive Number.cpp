class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int p1=0,p2=1;
        for(int i=1;i<=arr.back();++i)
        {
            if(arr[p1]==i) {
                ++p1;
                continue;
            }
            --k;
            if(k==0) return i;
            
        }
        return arr.back()+k;
    }
};
