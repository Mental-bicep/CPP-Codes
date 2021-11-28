class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        unordered_map<int,int> mp1,mp2;
        for(int i=0;i<grid.size();++i) for(int j=0;j<grid[i].size();++j) 
            if(grid[i][j]==1){
                ++mp1[i];++mp2[j];
            }
        int cnt=0;
        for(int i=0;i<grid.size();++i) for(int j=0;j<grid[i].size();++j) 
            if(grid[i][j] and ( mp1[i]>1 or mp2[j]>1 )) ++cnt;
        return cnt;
                
            
    }
};
