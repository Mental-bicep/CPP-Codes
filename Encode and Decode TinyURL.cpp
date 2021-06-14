class Solution {
public:

    // Encodes a URL to a shortened URL.
    unordered_map<string,string> mp1,mp2;
    unordered_map<string,bool> mp3;
    string alpha,digit;
    Solution(){
        alpha="abcdefghijklmnopqrstuvwxyz";
        digit="0123456789";
    }
    string encode(string s1) {
        if(mp1.find(s1)!=mp1.end()) return mp1[s1];
        string temp="http://tinyurl.com/";
        string temp2="";
        srand(time(NULL));
        while(true){
            for(int i=1;i<=11;++i){
                int num=rand()%2;
                char ch;
                if(num==0) ch=alpha[rand()%alpha.size()];
                else ch=digit[rand()%digit.size()];
                temp2.push_back(ch);
            }
            if(mp3[temp2]==false) break;
            temp2="";
        }
        temp=temp+temp2;
        mp1[s1]=temp;
        mp2[temp]=s1;
        mp3[temp2]=true;
        return temp;
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string s1) {
        return mp2[s1];
    }
};
