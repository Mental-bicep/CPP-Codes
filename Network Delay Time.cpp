#define f first
#define s second
class comp{
  public:
    bool operator ()(pair<int,int> &a,pair<int,int> &b)
    {
        return a.second>b.second;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      vector<int> vis(n+1,INT_MAX);  
      int ans=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq;    //vtx,wt
        vector<vector<pair<int,int>>> graph(n+1,vector<pair<int,int>>());
        for(auto &ele:times)
        {
            // cout<<"inside 1\n";
            graph[ele[0]].push_back({ele[1],ele[2]});
        }
        pq.push({k,0});
        while(pq.size()>0)
        {
            // cout<<"inside\n";
            
            auto rem=pq.top();pq.pop();
            // cout<<"val= "<<rem.f<<" "<<rem.s<<"\n";
            if(vis[rem.f]!=INT_MAX) continue;
            // cout<<"passed continue\n";
            vis[rem.f]=rem.s;
            // ans+=rem.s;
            for(auto &ele:graph[rem.f])
                if(vis[ele.f]==INT_MAX) pq.push({ele.f,rem.s+ele.s});
        }
    
        // for(int i=1;i<vis.size();++i) if(vis[i]==false) return -1;
        for(int i=1;i<vis.size();++i) {
            // if(vis[i]==INT_MAX) cout<<i<<" ";
            if(vis[i]==INT_MAX) return -1;
            // cout<<"i= "<<i<<" "<<vis[i]<<"\n";
            ans=max(ans,vis[i]);
        }
        // cout<<"\n";
        return ans;
    }
};
