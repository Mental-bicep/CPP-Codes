class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> stk1,stk2;
        for(auto ele:s) {
            if(ele=='#') {if(!stk1.empty()) stk1.pop();}
            else stk1.push(ele);
        }
        for(auto ele:t) {
            if(ele=='#') {if(!stk2.empty()) stk2.pop();}
            else stk2.push(ele);
        }
        string s1="",s2="";
        
        while(!stk1.empty()){
            auto ele=stk1.top();
            s1.push_back(ele);
            stk1.pop();
        }
        
        while(!stk2.empty()){
            auto ele=stk2.top();
            s2.push_back(ele);
            stk2.pop();
        }
        return s1==s2;
    }
};
