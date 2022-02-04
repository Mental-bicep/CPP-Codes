class Solution {
public:
    
    void fun(vector<vector<char>> &v1, int r,int c)
    {
        if(r<0 or c<0 or r>=v1.size() or c>=v1[r].size()) return ;
        if(v1[r][c]=='0') return ;
        v1[r][c]='0';
        fun(v1,r-1,c);
        fun(v1,r+1,c);
        fun(v1,r,c+1);
        fun(v1,r,c-1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[i].size();++j)
            {
                if(grid[i][j]=='1')
                {
                    ++cnt;
                    fun(grid,i,j);
                }
            }
        }
        return cnt;
    }
};
