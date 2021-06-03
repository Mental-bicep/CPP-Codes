class Solution {
public:
    int minOperations(int n) {
        int mid=n/2;
        if(n&1) return mid*(mid+1);
        return mid*mid;
    }
};
