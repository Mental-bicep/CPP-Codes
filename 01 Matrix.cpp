#define f first
#define s second
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size()));
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();++i)
            for(int j=0;j<grid[0].size();++j) if(grid[i][j]==0) q.push({i,j});
        int lvl=0;
        vector<int> dx={-1,0,1,0};
        vector<int> dy={0,1,0,-1};
        while(q.size()>0)
        {
            int size=q.size();
            while(size--)
            {
                auto rem=q.front();q.pop();
                if(vis[rem.f][rem.s]) continue;
                vis[rem.f][rem.s]=true;
                grid[rem.f][rem.s]=lvl;
                for(int i=0;i<4;++i)
                {
                    int nr=rem.f+dx[i];
                    int nc=rem.s+dy[i];
                    if(nr<0 or nc<0 or nr>=grid.size() or nc>=grid[0].size()) continue;
                    if(vis[nr][nc] or grid[nr][nc]==0) continue;
                    q.push({nr,nc});
                }
            }
            ++lvl;
        }
        return grid;
    }
};
