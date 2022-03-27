class Solution {
public:
    
    int fun(vector<vector<int>> &grid,int row,int col,vector<int> &dx,vector<int> &dy)
    {
        if(row<0 or col<0 or row>=grid.size() or col>=grid[0].size()) return 0;
        if(grid[row][col]==0) return 0;
        int ans=1;
        grid[row][col]=0;
        for(int i=0;i<4;++i)
            ans+=fun(grid,row+dx[i],col+dy[i],dx,dy);
        return ans;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int cnt=0;
        vector<int> dx={-1,0,1,0};
        vector<int> dy={0,1,0,-1};
        for(int i=0;i<grid.size();++i)
            for(int j=0;j<grid[0].size();++j)
                if(grid[i][j]==1) cnt=max(cnt,fun(grid,i,j,dx,dy));
        return cnt;
    }
};
