#define f first
#define s second
#define v vector
#define pb push_back
#define fori(a,b) for(int i=a;i<b;i++)
class Solution {
public:
    pair<int,int> fun(string &s1)
    {
        string state="out";
        int cnt1=0,cnt2=0;   //spaces ,words
        for(auto ele:s1)
        {
            if(ele==' ') {cnt1++; state="out";}
            else if(state=="out") {state="in";cnt2++;}
        }
        return make_pair(cnt1,cnt2);
    }
    
    v<string> fun2(string &s1)
    {
        char *arr = &(s1[0]);
    char *ptr = strtok(arr, " ");
    
    v<string> v1;
    while (ptr)
    {
         v1.pb(string(ptr));
       ptr = strtok(NULL, " ");
    }
        return v1;
    }
   
    string reorderSpaces(string s1)
    {
    auto ans = fun(s1);
            if(ans.s==1)
    {
        auto words=fun2(s1);
        string s2="";
        s2+=words[0];
        while(s2.size()!=s1.size()) s2+=' ';
        return s2;
    }
            int rem = ans.f / (ans.s - 1);
    int extra = ans.f - rem * (ans.s - 1);
        string s2="";
        auto words=fun2(s1);
        s2=accumulate(next(words.begin()),words.end(),words[0],[rem](string a,string b){
            for(int i=1;i<=rem;i++) a+=' ';
            return move(a)+b;
        });
            for (int i = 1; i <= extra; i++)
        s2 += ' ';
//     if(ans.s==1)
//     {
//         auto words=fun2(s1);
//         string s2="";
//         s2+=words[0];
//         while(s2.size()!=s1.size()) s2+=' ';
//         return s2;
//     }
//     int rem = ans.f / (ans.s - 1);
//     int extra = ans.f - rem * (ans.s - 1);
    
//     string s2 = "";
//     v<string> v1=fun2(s1);
    
//     fori(0, v1.size() - 1)
//     {
//         s2 += v1[i];
//         for (int j = 1; j <= rem; j++)
//             s2 += ' ';
//     }
//     s2 += v1[v1.size() - 1];
//     for (int i = 1; i <= extra; i++)
//         s2 += ' ';
    return s2;
    }
};
