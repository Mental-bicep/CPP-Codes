
template<typename t>
class graphs{
  unordered_map<t,list<pair<t,int >>> adjlist;
    vector<vector<int>> res;
    public:
    void addedge(t u ,t w,int wt=1,bool bidir=false){
        adjlist[u].push_back({w,wt});
        if(bidir) adjlist[w].push_back({u,wt});
    }
    void dfs_helper(t node,unordered_map<t,bool> &visited,int tar,vector<int>&v1){
        if(node==tar){
            res.push_back(v1);
            return ;    
        }
        visited[node]=true;
        
        
        for (auto ele : adjlist[node])
        {
            if (!visited[ele.first]){
                v1.push_back(ele.first);
                dfs_helper(ele.first, visited,tar,v1);
                v1.pop_back();
            }
        }
        visited[node]=false;
    }
    vector<vector<int>> dfs(int src,int tar)
    {
        unordered_map<t, bool> visited;        
            vector<int> v1;
            v1.push_back(src);
            dfs_helper(src, visited,tar,v1);
        return res;
    }
    
};
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
      // if(graph.size()==0){
      //      vector<vector<int>> v;
      //     return v;
      // }
        if(graph.size()==1){
            vector<vector<int>> v1(1,vector<int>(1,0));
            return v1;
        }
        graphs<int> g;
        for(int i=0;i<graph.size();++i)
            for(int j=0;j<graph[i].size();++j) 
                g.addedge(i,graph[i][j]);
        auto v1=g.dfs(0,graph.size()-1);
        return v1;
    }
};
