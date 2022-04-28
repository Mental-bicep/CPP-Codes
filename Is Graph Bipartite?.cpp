class Solution {
public:
    bool fun(vector<vector<int>> &graph,int src,vector<int> &vis)
    {
        queue<pair<int,int>> q;
        q.push({src,0});
        while(q.size()>0)
        {
            auto rem=q.front();q.pop();
            if(vis[rem.first]!=0)
            {
                if(vis[rem.first]!=rem.second) return false;
            }
            vis[rem.first]=rem.second;
            for(auto &ele:graph[rem.first])
                if(vis[ele]==0) {
                    if(rem.second==0) q.push({ele,1});
                    else q.push({ele,0});
                }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(),0);
        for(int i=0;i<graph.size();++i) 
            if(vis[i]==0){
                auto ans=fun(graph,i,vis);
                if(!ans) return ans;
            }
        return true;
    }
};
