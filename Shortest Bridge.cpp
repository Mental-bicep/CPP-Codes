#define f first
#define s second
class Solution {
public:
    vector<int> dx={-1,0,1,0};
    vector<int> dy={0,1,0,-1};
    void dfs1(int r,int c,vector<vector<int>> &grid,vector<vector<bool>> &vis,queue<pair<int,int>> &q)
    {
        vis[r][c]=true;
        q.push({r,c});
        for(int i=0;i<4;++i)
        {
            int nr=r+dx[i];
            int nc=c+dy[i];
            if(nr<0 or nc<0 or nr>=grid.size() or nc>=grid[0].size()) continue;
            if(vis[nr][nc] or grid[nr][nc]!=1) continue;
            dfs1(nr,nc,grid,vis,q);
        }
    }
    
    int bfs(queue<pair<int,int>> &q,vector<vector<int>>&grid,vector<vector<bool>>&vis)
    {
        int lvl=0;
        while(q.size()>0)
        {
            int size=q.size();
            while(size--)
            {
                auto rem=q.front();q.pop();
                int r=rem.f;
                int c=rem.s;
                for(int i=0;i<4;++i)
                {
                    int nr=r+dx[i];
                    int nc=c+dy[i];
                    if(nr<0 or nc<0 or nr>=grid.size() or nc>=grid[0].size()) continue;
                    if(vis[nr][nc] ) continue;
                    if(grid[nr][nc]==1) return lvl;
                    vis[nr][nc]=true;
                    q.push({nr,nc});
                }
            }
            ++lvl;
        }
        return -1;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size()));
        for(int i=0;i<grid.size();++i){
            bool flag=false;
            for(int j=0;j<grid[0].size();++j)
                if(grid[i][j]==1 and !vis[i][j])
                {
                    flag=true;
                    dfs1(i,j,grid,vis,q);         // rem
                    break;
                }
            if(flag) break;
        }
        int ans=bfs(q,grid,vis);   // rem
        return ans;
        
    }
};
