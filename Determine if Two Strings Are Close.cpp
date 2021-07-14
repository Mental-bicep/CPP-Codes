#define umap unordered_map 
#define s second
#define amp &
#define ins insert
#define rn return 
#define rng(x) x.begin(),x.end()
#define bn begin
#define rsg resize
class Solution {
public:
    bool closeStrings(string s1, string s2) {
        if(s1.size()!=s2.size()) rn false;
        umap<char,int> mp1,mp2;
        for(auto amp ele:s1) ++mp1[ele];
        for(auto amp ele:s2)  ++mp2[ele];
        multiset<int> st1,st2;
        for(auto amp ele:mp1) st1.ins(ele.s);
        for(auto amp ele:mp2) st2.ins(ele.s);
        
        if(st1!=st2) rn false;
        mp1.clear();mp2.clear();
        set<char> set1(rng(s1)),set2(rng(s2));
        if(set1==set2) rn true;
        rn false;
        
    }
};
