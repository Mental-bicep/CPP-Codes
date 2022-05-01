class Solution {
public:
    int find(int x,vector<int>&par)
    {
        if(x==par[x]) return x;
        return par[x]=find(par[x],par);
    }
    
    bool equationsPossible(vector<string>& equations) {
        vector<int> par(27),rank(27);
        vector<int> par2(27),rank2(27);
        // sort(equations.begin(),equations.end(),[](auto &a,auto &b){
        //     if(a[1]=='=') return true;
        //     else if(b[1]=='=') return false;
        //     return true;
        // });
        for(int i=0;i<par.size();++i) par[i]=i,rank[i]=1,par2[i]=i,rank2[i]=1;
        for(auto &ele:equations)
        {
            char ch1=ele[0],ch2=ele[3];
            int lx=find(ch1-'a',par);
            int ly=find(ch2-'a',par);
            
            // int lx1=find(ch1-'a',par2);
            // int ly1=find(ch2-'a',par2);
            
            if(ele[1]=='=')
            {
                // if(lx1==ly1) return false;
                if(lx!=ly){
                    if(rank[lx]>rank[ly]) par[ly]=lx,rank[lx]+=rank[ly];
                    else par[lx]=ly,rank[ly]+=rank[lx];
                }
            }
            // else{
            //     if(lx==ly) return false;
            //     if(lx1!=ly1){
            //         if(rank2[lx1]>rank2[ly1]) par2[ly1]=lx1,rank2[lx1]+=rank2[ly1];
            //         else par2[lx1]=ly1,rank2[ly1]+=rank2[lx1];
            //     }
            // }
        }
        
        for(auto &ele:equations)
        {
            if(ele[1]!='!') continue;
            char ch1=ele[0],ch2=ele[3];
            int lx=find(ch1-'a',par);
            int ly=find(ch2-'a',par);
            if(lx==ly) return false;
        }
        
        return true;
    }
};
