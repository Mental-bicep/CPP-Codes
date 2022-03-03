class Solution {
public:

    int find(int x,vector<int>&par)
    {
        if(x==par[x]) return x;
        return par[x]=find(par[x],par);
    }
    
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n=source.size();
        vector<int> par(n);
        for(int i=0;i<n;++i) par[i]=i;
        vector<int> rank(n,1);
        for(vector<int> swap:allowedSwaps)
        {
            int a=swap[0];
            int b=swap[1];
            int lx=find(a,par);
            int ly=find(b,par);
            if(lx!=ly)
            {
                if(rank[lx]>rank[ly]) par[ly]=lx;
                else if(rank[ly]>rank[lx]) par[lx]=ly;
                else{
                    par[lx]=ly;
                    ++rank[ly];
                }
            }
        }
        
        unordered_map<int,unordered_map<int,int>> mp1;
        for(int i=0;i<n;++i)
        {
            int lx=find(i,par);
            int val=source[i];
            ++mp1[lx][val];
        }
        
        int hd=0;
        for(int i=0;i<n;++i)
        {
            int lx=find(i,par);
            int val=target[i];
            if(mp1[lx][val]<=0) {
                ++hd;continue;}
            --mp1[lx][val];
            
        }
        return hd;
        
    }
};
