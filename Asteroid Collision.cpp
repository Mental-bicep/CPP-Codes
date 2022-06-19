class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v1) {
        stack<int> st;
        for(int i=0;i<v1.size();++i)
        {
            if(st.size()==0 or v1[i]>0) st.push(v1[i]);
            else {
                bool flag=true;
                while(st.size()>0 and st.top()>0)
                {
                    if(abs(v1[i])>st.top()) st.pop();
                    else if(st.top()>abs(v1[i])) {
                        flag=false;
                        break;
                    }
                    else {
                        st.pop();
                        flag=false;
                        break;
                    }
                    
                }
                if(flag) st.push(v1[i]);
            }
        }
        vector<int> res;
        while(st.size()>0) res.push_back(st.top()),st.pop();
        reverse(res.begin(),res.end());
        return res;
    }
};
