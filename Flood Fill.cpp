int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
class Solution {
public:
    void floodfill(vector<vector<int>>&v1,int x,int y,int req_col,int new_col){
        if(x<0 or x>=v1.size() or y<0 or y>=v1[0].size()) return ;
        if(v1[x][y]!=req_col) return ;
        v1[x][y]=new_col;
        for(int i=0;i<4;++i) floodfill(v1,x+dx[i],y+dy[i],req_col,new_col);
        return ;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]!=newColor)
        floodfill(image,sr,sc,image[sr][sc],newColor);
        return image;
    }
};
