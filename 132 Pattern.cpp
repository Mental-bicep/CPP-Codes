class Solution {
public:
    bool find132pattern(vector<int>& v1) {
       
    
    int n=v1.size();
    vector<int> pmin(n);
    pmin[0]=v1[0];
    for(int i=1;i<n;++i) pmin[i]=min(pmin[i-1],v1[i]); 
    stack<int> st;
    bool flag=false;
    for(int i=n-1;i>=0;--i)
    {
        while(st.size()>0 and st.top()<=pmin[i]) st.pop();
        if(st.size()>0 and st.top()<v1[i]) {
            flag=true;
            break;
        }
        st.push(v1[i]);
    }
    return flag;
        
    }
};
