class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> v1;
        for(int i=left;i<=right;++i){
            string s1=to_string(i);
            // if(s1.find('0')==string::npos){
                bool flag=true;
                for(auto ele:s1) if(ele=='0' or i%(ele-'0')!=0) {flag=false;break;}
                if(flag) v1.push_back(i);
            // }
        }
        return v1;
    }
};
