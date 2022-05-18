#define f first
#define s second
class Solution {
public:
    vector<int> dx={-1,0,1,0};
    vector<int> dy={0,1,0,-1};
    int bfs(queue<pair<int,int>>&q,vector<vector<int>> &grid,vector<vector<bool>> &vis)
    {
        int lvl=0;
        while(q.size()>0){
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
                    if(vis[nr][nc]) continue;
                    vis[nr][nc]=true;
                    q.push({nr,nc});
                }
            }
            ++lvl;
        }
        return lvl-1;
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size()));
        for(int i=0;i<grid.size();++i)
            for(int j=0;j<grid[0].size();++j)
                if(grid[i][j]==1) q.push({i,j}),vis[i][j]=true;
        if(q.size()==0 or q.size()==grid.size()*grid.size()) return -1;
        int ans=bfs(q,grid,vis);
        return ans;
    }
};
