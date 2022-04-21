class Solution {
public:
    vector<int> kahns(int n,vector<vector<int>> &graph)
{
    vector<int> indegree(n,0);
    
        vector<vector<int>> adj(n);
        for(auto &ele:graph) {++indegree[ele[1]];
            adj[ele[0]].push_back(ele[1]);                     
        }
        
        queue<int> q;
    for(int i=0;i<indegree.size();++i) 
        if(indegree[i]==0) q.push(i);
    vector<int> ans;
    while(q.size())
    { 
        // cout<<"inside loop\n";
        int rem=q.front();q.pop();
        ans.push_back(rem);
        for(auto &ele:adj[rem])
        {
            --indegree[ele];
            if(indegree[ele]==0) q.push(ele);
        }
    }
    if(ans.size()!=indegree.size()) {
        // cout<<"cycle\n";  
        // return false;
        return {};
    }
        reverse(ans.begin(),ans.end());
    return ans ;
}
    
    
    vector<int> findOrder(int n, vector<vector<int>>& graph) {
        return kahns(n,graph);
    }
};
