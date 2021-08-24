class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& v1) {
        if(v1[0][0]==1) return 0;
        for(int i=0;i<v1[0].size();++i){ 
            bool flag=false;
            if(v1[0][i]==0) v1[0][i]=1;
            else{
                v1[0][i]=0;
                for(int j=i+1;j<v1[0].size();++j) v1[0][j]=0;
                flag=true;
                break;
            }
            if(flag) break;
                                        
            }
        for(int i=1;i<v1.size();++i){   // mistake here was starting from i=0
            bool flag=false;
            if(v1[i][0]==0) v1[i][0]=1;
            else{
                v1[i][0]=0;
                for(int j=i+1;j<v1.size();++j) v1[j][0]=0;
                flag=true;
                break;
            }
            if(flag) break;
        }
        
        for(int i=1;i<v1.size();++i) 
            for(int j=1;j<v1[0].size();++j){
                if(v1[i][j]==1) v1[i][j]=0;
                else v1[i][j]=v1[i-1][j]+v1[i][j-1];
            }
        return v1[v1.size()-1][v1[0].size()-1];
            
    }
};
