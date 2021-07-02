class Solution {
public:
    int maximum69Number (int num) {
        string str=to_string(num);
        // auto idx=str.rfind("9");
        // if(idx!=string::npos)
        // str[idx]='6';
        auto idx=str.find("6");
        if(idx!=string::npos)
        str[idx]='9';
        num=stoi(str);
        return num;
        
    }
};

