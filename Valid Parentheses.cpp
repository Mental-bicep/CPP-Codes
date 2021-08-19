class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2!=0) return false;
        stack<char> st;
        for(auto &ele:s){
            if(ele=='{' or ele=='(' or ele=='[') st.push(ele);
            else if(ele==')'){
                if(st.empty()) return false;
                if(st.top()!='(') return false;
                st.pop();
            }
            else if(ele=='}'){
                if(st.empty()) return false;
                if(st.top()!='{') return false;
                st.pop();
            }
            else if(ele==']'){
                if(st.empty()) return false;
                if(st.top()!='[') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
