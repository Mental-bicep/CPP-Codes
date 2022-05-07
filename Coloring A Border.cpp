class Solution {
public:
    vector<int> dx,dy;
    void fun(vector<vector<int>> &grid,vector<vector<bool>> &vis,int r,int c,int &val,int &col)
    {
        vis[r][c]=true;
        int cnt=0;
        for(int i=0;i<4;++i)
        {
            int nr=r+dx[i];
            int nc=c+dy[i];
            if(nr<0 or nc<0 or nr>=grid.size() or nc>=grid[0].size()) continue ;
            if(grid[nr][nc]==val) ++cnt;
            else if(grid[nr][nc]==col and vis[nr][nc]) ++cnt;
                
            if(vis[nr][nc] or grid[nr][nc]!=val) continue;
            
            fun(grid,vis,nr,nc,val,col);
        }
        // if(r==1 and c==1) cout<<"cnt = "<<cnt<<'\n';
        if(cnt<4) grid[r][c]=col;
    }
    
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        dx=vector<int>{-1,0,1,0};
        dy=vector<int>{0,1,0,-1};
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));
        fun(grid,vis,row,col,grid[row][col],color);
        // for(auto &ele:grid){
        //     for(auto &itms:ele) cout<<itms<<" ";
        //     cout<<"\n";
        // }
        return grid;
    }
}; 
