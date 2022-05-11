class Solution {
public:
    vector<int> dx={-1,0,1,0};
    vector<int> dy={0,1,0,-1};
    
    int dfs(vector<vector<int>> &grid,vector<vector<bool>> &vis,int r,int c)
    {
        if(grid[r][c]==2) return 0;
        vis[r][c]=true;
        int ans=INT_MAX;        
        for(int i=0;i<4;++i)
        {
            int nr=r+dx[i];
            int nc=c+dy[i];
            if(nr<0 or nc<0 or nr>=grid.size() or nc>=grid[0].size()) continue;
            if(vis[nr][nc] or grid[nr][nc]==0) continue;
            ans=min(ans,dfs(grid,vis,nr,nc));
        }
        if(ans!=INT_MAX) ++ans;
        vis[r][c]=false;
        return ans;
    }
        
    
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size()));
        int oans=0;
        for(int i=0;i<grid.size();++i)
            for(int j=0;j<grid[0].size();++j)
                if(grid[i][j]==1) 
                {   
                    int ans=dfs(grid,vis,i,j);
                    oans=max(oans,ans);
                    vis=vector<vector<bool>>(grid.size(),vector<bool>(grid[0].size()));
                }
        if(oans==INT_MAX) return -1;
        return oans;
    }
};
