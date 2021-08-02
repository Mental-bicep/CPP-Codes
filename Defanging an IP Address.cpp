class Solution {
public:
    string defangIPaddr(string address) {
        string s;
        for(auto ele:address)
        {
            if(ele=='.') s+="[.]";
            else s+=ele;
        }
        return s;
        
    }
};
