class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int k=0;
        for(int i=0;i<pushed.size();)
        {
            if(st.size()==0 or st.top()!=popped[k]) st.push(pushed[i++]);
            else if(st.top()==popped[k]) k++,st.pop();
        }
        while(st.size()>0 and st.top()==popped[k]) st.pop(),k++;
        return k==popped.size();
    }
};
