#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // unordered_map<int,unordered_set<int>> rows,cols;
    vector<vector<bool>> rows,cols;
    vector<vector<vector<bool>>> mat;
    
    bool solveSudoku(vector<vector<char>> &board, int idx, vector<pair<int, int>> &cells)
    {
        if (idx == cells.size())
            return true;

        // int r = cells[idx] / 9, c = cells[idx] % 9;
        int r = cells[idx].first, c = cells[idx].second;
        for (int num = 1; num <= 9; num++)
        {
            if (!rows[r][num] && !cols[c][num] && !mat[r/3][c/3][num])
            {
                board[r][c] = (char)('0' + num);
                // rows[r].insert(num);
                // cols[c].insert(num);
                // mat[r][c][num]=true;
                rows[r][num]=true;
                cols[c][num]=true;
                mat[r/3][c/3][num]=true;
                if (solveSudoku(board, idx + 1, cells))
                    return true;
                board[r][c] = '.';
                rows[r][num]=false;
                cols[c][num]=false;
                mat[r/3][c/3][num]=false;
                
                // rows[r].erase(num);
                // cols[c].erase(num);
                // mat[r][c][num]=false;
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        // vector<int> cells;
        rows.resize(10,vector<bool>(10,false));
        cols.resize(10,vector<bool>(10,false));
        mat.resize(3,vector<vector<bool>>(3,vector<bool>(10,false)));
        vector<pair<int, int>> cells;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    // cells.push_back(i * 9 + j);
                    cells.push_back({i, j});
                }
                else {
                    int num=board[i][j]-'0';
                    // rows[i].insert(num);
                    // cols[j].insert(num);
                    rows[i][num]=true;
                    cols[j][num]=true;
                    mat[i/3][j/3][num]=true;
                }
            }
        }

        solveSudoku(board, 0, cells);
    }
};
