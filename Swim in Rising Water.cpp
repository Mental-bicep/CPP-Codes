class Pair{
  public:
  int row;
  int col;
  int msf;
  Pair(int row,int col,int msf)
  {
      this->row=row;
      this->col=col;
      this->msf=msf;
  }
};

class comp{
    public:
    bool operator ()(Pair a,Pair b)
    {
        return a.msf>b.msf;
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<Pair,vector<Pair>,comp> pq;
    pq.push(Pair(0,0,grid[0][0]));
    vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size()));
    vector<int> dx={-1,0,1,0};
    vector<int> dy={0,1,0,-1};
    while(pq.size()>0)
    {
        Pair rem=pq.top();
        pq.pop();
        if(rem.row==grid.size()-1 and rem.col==grid[0].size()-1)
            return rem.msf;
        if(vis[rem.row][rem.col]) continue;
        vis[rem.row][rem.col]=true;
        for(int i=0;i<4;++i)
        {
            int row=rem.row+dx[i];
            int col=rem.col+dy[i];
            if(row<0 or col<0 or row>=grid.size() or col>=grid[0].size() or vis[row][col]) continue;
            pq.push(Pair(row,col,max(rem.msf,grid[row][col])));
        }
    }
    return 0;
    }
};
