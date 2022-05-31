class Solution {
public:
    int minAddToMakeValid(string s1) {
        stack<char> st;
        for(int i=0;i<s1.size();++i)
        {
            if(s1[i]=='(') st.push(s1[i]);
            else{
                if(st.size()>0 and st.top()=='(')  st.pop();
                else st.push(')');
            }
        }
        return st.size();
    }
};
