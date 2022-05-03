class Solution {
public:
    int find(int x,vector<int>&par)
    {
        if(x==par[x]) return x;
        return par[x]=find(par[x],par);
    }
    
    string smallestStringWithSwaps(string s1, vector<vector<int>>& pairs) {
        vector<int> par(s1.size()),rank(s1.size());
        for(int i=0;i<par.size();++i) par[i]=i,rank[i]=1;
        for(auto &ele:pairs)
        {
            int lx=find(ele[0],par);
            int ly=find(ele[1],par);
            if(lx!=ly){
                    if(rank[lx]>rank[ly]) par[ly]=lx,rank[lx]+=rank[ly];
                    else par[lx]=ly,rank[ly]+=rank[lx];
                }
        }
        
        unordered_map<int,multiset<char>> mp1;
        for(int i=0;i<s1.size();++i)
        {
            int lx=find(i,par);
            mp1[lx].insert(s1[i]);
        }
        string ans;
        for(int i=0;i<s1.size();++i)
        {
            int lx=find(i,par);
            char ch=*(mp1[lx].begin());              // get data
            mp1[lx].erase(mp1[lx].begin());                                           // remvoe data
            ans.push_back(ch);
        }
        return ans;
    }
};
