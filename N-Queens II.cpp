class Solution {
public:
    
    unordered_map<int,bool> row,col,adiag,diag;
    
    int fun(int n,int m,int c_row)
{
    if(c_row==n)
    {
        return 1;
    }
    int cnt=0;
    for(int i=0;i<m;++i)
    {
        int r=c_row;
        int c=i;
        if(!row[r] and !col[c] and !adiag[r-c] and !diag[r+c] )
            {   
                row[r]  =col[c]  =adiag[r-c] = diag[r+c]=true;
                cnt+=fun(n,m,c_row+1);
                row[r]  =col[c]  =adiag[r-c] = diag[r+c]=false;
            }
    }
    return cnt;

}
    
    int totalNQueens(int n) {
        int ans=fun(n,n,0);
        return ans;
    }
};
