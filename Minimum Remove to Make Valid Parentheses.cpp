class Solution {
public:
    string minRemoveToMakeValid(string s1) {
        stack<int> st;
        for(int i=0;i<s1.size();++i)
        {
            if(s1[i]=='(') st.push(i);
            else if(s1[i]==')'){
                if(st.size()>0) st.pop();
                else s1[i]='.';
            }
        }
        while(st.size()>0)
        {
            int idx=st.top();st.pop();
            s1[idx]='.';
        }
        string ans;
        for(auto &ele:s1) if(ele!='.') ans.push_back(ele);
        return ans;
    }
};
