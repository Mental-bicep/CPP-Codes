class Solution {
public:
    // -1 first time, -2 alredy in bfs , ele bfs completed
    bool dfs(vector<vector<int>> &graph,int src,vector<int> &v1,unordered_map<int,bool> &mp1)
    {
        v1[src]=-2;
        bool flag=true;
        for(auto &ele:graph[src])
        {
            if(v1[ele]==-1) {if(!dfs(graph,ele,v1,mp1)) flag=false;}
            else if(v1[ele]==ele){ 
                if(!mp1[ele]) flag=false; 
                continue;
            }
            else if(v1[ele]==-2) flag=false;
        }
        v1[src]=src;
        mp1[src]=flag;
        return flag;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // unordered_map<int,bool> mp1;
        unordered_map<int,bool> mp1;
        vector<int> v1(graph.size(),-1);
        for(int i=0;i<graph.size();++i)
        {
            if(v1[i]==-1) dfs(graph,i,v1,mp1);
            // else 
        }
        vector<int> res;
        for(auto &ele:mp1) if(ele.second) res.push_back(ele.first);
        sort(res.begin(),res.end());
        return res;
    }
};
