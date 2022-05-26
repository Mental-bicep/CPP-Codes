class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int tar) {
        int r=0,c=mat[0].size()-1;
        while(r<mat.size() and c>=0  )
        {
            if(mat[r][c]==tar) return true;
            if(mat[r][c]>tar) --c;
            else ++r;
        }
        return false;
    }
};
