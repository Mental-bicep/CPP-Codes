class Pair{
  public:
    int r,c,wt;
    Pair(int r,int c,int wt)
    {
        this->r=r;
        this->c=c;
        this->wt=wt;
    }
};

class comp{
  public:
    bool operator ()(Pair &a,Pair &b)
    {
        return a.wt>b.wt;
    }
};





class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& height) {
        priority_queue<Pair,vector<Pair>,comp>q;
        q.push(Pair(0,0,0));
        vector<int> dx={-1,0,1,0};
        vector<int> dy={0,1,0,-1};
        while(q.size()>0)
        {
            auto rem=q.top();q.pop();
            //vis
            if(height[rem.r][rem.c]<0) continue;
            if(rem.r==height.size()-1 and rem.c==height[0].size()-1)
                return rem.wt;
            height[rem.r][rem.c]=-height[rem.r][rem.c];
            for(int i=0;i<4;++i)
            {
                int nr=rem.r+dx[i];
                int nc=rem.c+dy[i];
                if(nr<0 or nc<0 or nr>=height.size() or nc>=height[0].size())
                    continue;
                if(height[nr][nc]<0) continue;
                int diff=abs(abs(height[rem.r][rem.c])-height[nr][nc]);
                q.push(Pair(nr,nc,max(rem.wt,diff)));
            }
        }
        return 0;
    }
};
