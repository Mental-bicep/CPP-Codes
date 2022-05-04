class Solution {
public:
    int find(int x,vector<int>&par)
    {
        if(x==par[x]) return x;
        return par[x]=find(par[x],par);
    }
    
    int makeConnected(int n, vector<vector<int>>& conn) {
        int alreadySame=0,diff=0;
        vector<int> par(n),rank(n);
        for(int i=0;i<par.size();++i) par[i]=i,rank[i]=1;
        for(auto &ele:conn)
        {
            int lx=find(ele[0],par);
            int ly=find(ele[1],par);
            if(lx!=ly){
                    
                    if(rank[lx]>rank[ly]) par[ly]=lx,rank[lx]+=rank[ly];
                    else par[lx]=ly,rank[ly]+=rank[lx];
                }
            else ++alreadySame;
        }
        unordered_set<int> st1;
        // for(int i=0;i<par.size();++i) {st1.insert(par[i]);cout<<par[i]<<" ";}
        // cout<<"\n";
        // cout<<par[3]<<"\n";
        // cout<<"st1 size = "<<st1.size()<<"\n";
        for(int i=0;i<par.size();++i)
        {
            int lx=find(i,par);
            st1.insert(lx);
        }
        if(alreadySame>=st1.size()-1) return st1.size()-1;
        return -1;
        
        
        
    }
};
