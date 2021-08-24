#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
     stable_partition(A.begin(),A.end(),[](auto a){return a%2==0;});
        return A;
    }
};
