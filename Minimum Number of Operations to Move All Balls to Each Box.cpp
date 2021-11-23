class Solution {
public:
    vector<int> minOperations(string s1) {
        vector<int> v2(s1.size()),v3(s1.size());
        v2[0]=0;
        v3[v3.size()-1]=0;
        int cnt=0;
        for(int i=1;i<s1.size();++i) {
            v2[i]=v2[i-1]+cnt;
            if(s1[i-1]=='1') {++v2[i];++cnt;}
        }
        cnt=0;
        for(int i=s1.size()-2;i>=0;--i){
            v3[i]=v3[i+1]+cnt;
            if(s1[i+1]=='1') {++v3[i];++cnt;}
        }
        for(int i=0;i<v2.size();++i) v2[i]+=v3[i];
        return v2;
    }
};
