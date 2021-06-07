#define v vector
#define f first
#define s second
#define rn return
#define sz size
#define p pair
#define mp make_pair
#define ll int
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& v1) {
        v<v<int>> v2(v1.sz(),v<int>(v1[0].sz(),-1));
        queue<p<int,int>> q;
        for(int i=0;i<v1.sz();++i) for(int j=0;j<v1[i].sz();++j)
            if(v1[i][j]==1) {
                q.push(mp(i,j));
                v2[i][j]=0;
            }
        while(!q.empty()){
            // cout<<"inside queue\n";
            auto ele=q.front();
            q.pop();
            v<ll>dx={-1,0,1,0};
            v<ll>dy={0,-1,0,1};
            for(int i=0;i<4;++i){
                int row=ele.f+dx[i];
                int col=ele.s+dy[i];
                // cout<<"outside for "<<row<<" "<<col<<"\n";
                if(row>=0 and row<v1.sz() and col>=0 and col<v1[0].sz() and v2[row][col]==-1 ){   // imp tt
                    // cout<<"inside for "<<row<<" "<<col<<"\n";
                    v2[row][col]=v2[ele.f][ele.s]+1;
                    q.push(mp(row,col));
                }
            }
        }
        rn v2;
    }
};
