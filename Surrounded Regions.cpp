class Pair{
    int r;
    int c;
    Pair(int r,int c)
    {
        this.r=r;
        this.c=c;
    }
}
class Solution {
    public void solve(char[][] board) {
        Queue<Pair> q=new LinkedList<>();
        for(int i=0;i<board.length;++i)
            for(int j=0;j<board[0].length;++j)
                if(i==0 || j==0 || i==board.length-1 || j==board[0].length-1)
                    if(board[i][j]=='O') q.add(new Pair(i,j));
        int []dx={-1,0,1,0};
        int []dy={0,1,0,-1};
        while(q.size()>0)
        {
            Pair rem=q.remove();
            if(board[rem.r][rem.c]=='k') continue;
            board[rem.r][rem.c]='k';
            for(int i=0;i<4;++i)
            {
                int nr=rem.r+dx[i];
                int nc=rem.c+dy[i];
                if(nr<0 || nc<0 || nr>=board.length || nc>=board[0].length) 
                    continue;
                if(board[nr][nc]!='O') continue;
                q.add(new Pair(nr,nc));
            }
        }
        
        for(int i=0;i<board.length;++i)
            for(int j=0;j<board[0].length;++j)
            {
                if(board[i][j]=='k') board[i][j]='O';
                else board[i][j]='X';
            }
        return ;
        
    }
}
