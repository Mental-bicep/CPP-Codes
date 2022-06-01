class Solution {
public:
    string removeOuterParentheses(string s1) {
        stack<char> st;
        string ans;
        for(int i=0;i<s1.size();++i)
        {
            if(s1[i]=='('){
                if(st.size()>0) ans.push_back('(');
                st.push('(');
            }
            else{
                if(st.size()>1) ans.push_back(')');
                st.pop();
            }
        }
        return ans;
    }
};
