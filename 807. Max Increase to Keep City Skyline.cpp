#define umap unordered_map
#define ll int
#define sz size
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        umap<int,int> rows,cols;
        for(ll i=0;i<grid.sz();++i){
            ll ans=LLONG_MIN;
            for(ll j=0;j<grid[i].sz();++j)
                ans=max(ans,grid[i][j]);
            rows[i]=ans;
        }
        
        for(ll i=0;i<grid[0].sz();++i){
            ll ans=LLONG_MIN;
            for(ll j=0;j<grid.sz();++j)
                ans=max(ans,grid[j][i]);
            cols[i]=ans;
        }
        ll ans=0;
        for(ll i=0;i<grid.sz();++i){
            
            for(ll j=0;j<grid[i].sz();++j)
                if(grid[i][j]<min(rows[i],cols[j])) 
                    ans+=min(rows[i],cols[j])-grid[i][j];
            
        }
        return ans;
    }
};
