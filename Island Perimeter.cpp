class Solution {
public:
    vector<int> dx={-1,0,1,0};
    vector<int> dy={0,1,0,-1};
    void fun(vector<vector<int>> &grid,int r,int c,int &ans,vector<vector<bool>> &vis)
    {
        if(vis[r][c] or grid[r][c]==0) return ;
        vis[r][c]=true;
        int  cnt=4;
        for(int i=0;i<4;++i)
        {
            int nr=r+dx[i];
            int nc=c+dy[i];
            if(nr<0 or nc<0 or nr>=grid.size() or nc>=grid[0].size()) continue;
            if(grid[nr][nc]==1) --cnt;
            fun(grid,nr,nc,ans,vis);
        }
        ans+=cnt;
    }
    
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0;
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size()));
        for(int i=0;i<grid.size();++i)
            for(int j=0;j<grid[0].size();++j) 
                if(grid[i][j]==1) {
                    fun(grid,i,j,ans,vis);
                    return ans;
                    // break;
                }
        return 0;
    }
};
