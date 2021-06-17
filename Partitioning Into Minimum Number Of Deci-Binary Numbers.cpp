class Solution {
public:
    int minPartitions(string n) {
        auto it=*max_element(n.begin(),n.end());
        // char ch=*it;
        return it-'0';
    }
};
