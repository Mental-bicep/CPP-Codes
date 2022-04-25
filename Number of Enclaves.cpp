#define f first
#define s second
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n=grid.size(),m=grid[0].size();
        for(int j=0;j<grid[0].size();++j) if(grid[0][j]==1) q.push({0,j});
        for(int j=0;j<grid[0].size();++j) if(grid[n-1][j]==1) q.push({n-1,j});
        for(int i=0;i<grid.size();++i) if(grid[i][0]==1) q.push({i,0});
        for(int i=0;i<grid.size();++i) if(grid[i][m-1]==1) q.push({i,m-1});
        vector<vector<bool>> vis(n,vector<bool>(m));
        vector<int> dx={-1,0,1,0},dy={0,1,0,-1};
        while(q.size()>0)
        {
            auto rem=q.front();q.pop();
            if(vis[rem.f][rem.s]) continue;
            vis[rem.f][rem.s]=true;
            grid[rem.f][rem.s]=2;
            for(int i=0;i<4;++i)
            {
                int r=rem.f+dx[i];
                int c=rem.s+dy[i];
                if(r<0 or c<0 or r>=n or c>=m) continue;
                if(grid[r][c]!=1) continue;
                q.push({r,c});
            }
        }
        int cnt=0;
        for(int i=0;i<grid.size();++i)
            for(int j=0;j<grid[0].size();++j) if(grid[i][j]==1) ++cnt;
        return cnt;
        
        
    }
};
