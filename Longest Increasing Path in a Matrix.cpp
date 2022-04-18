class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // queue<pair<int,int>> q;
        vector<int> dx={-1,0,1,0};
        vector<int> dy={0,1,0,-1};
        map<pair<int,int> ,int> mp1;
        for(int i=0;i<matrix.size();++i)
            for(int j=0;j<matrix[0].size();++j)
            {
                for(int k=0;k<4;++k)
                {
                    int nr=i+dx[k];
                    int nc=j+dy[k];
                    if(nr<0 or nc<0 or nr>=matrix.size() or nc>=matrix[0].size()) continue;
                    if(matrix[nr][nc]<=matrix[i][j]) continue;
                    // cout<<"adding for nr and nc "<<nr<<" "<nc<<"\n";
                    // cout<<"adding nr and nc "<<nr<<" "<<nc<<"\n";
                    ++mp1[{nr,nc}];
                }
            }
        int level=0;
        queue<pair<int,int>> q;
        // for(auto &ele:mp1) if(ele.second==0) q.push(ele.first);
        for(int i=0;i<matrix.size();++i)
            for(int j=0;j<matrix[0].size();++j) 
                if(mp1[{i,j}]==0) {q.push({i,j});//cout<<"i and j "<<i<<" "<<j<<"\n";
                                  }
        // cout<<"q.size "<<q.size()<<"\n";
        while(q.size()>0)
        {
            // cout<<"inside loop\n";
            int size=q.size();
            while(size--)
            {
                auto rem=q.front();q.pop();
                for(int i=0;i<4;++i)
                {
                    int nr=rem.first+dx[i];
                    int nc=rem.second+dy[i];
                    if(nr<0 or nc<0 or nr>=matrix.size() or nc>=matrix[0].size()) continue;
                    if(matrix[nr][nc]<=matrix[rem.first][rem.second]) continue;
                    // ++mp1[{nr,nc}];
                    --mp1[{nr,nc}];
                    if(mp1[{nr,nc}]==0) q.push({nr,nc});
                }
            }
            ++level;
        }
        return level;
        
    }
};
