#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool f(int rows, int cols, vector<vector<char>> &board, int i, int j,
       int idx, string &word)
{
    if (idx == word.size())
        return true;

    if (i < 0 || j < 0 || i >= rows || j >= cols || board[i][j] == '$')
        return false;

    if (board[i][j] != word[idx])
        return false;

    char temp = board[i][j];
    board[i][j] = '$';

    for (auto it : directions)
    {
        int new_i = i + it[0];
        int new_j = j + it[1];

        if (f(rows, cols, board, new_i, new_j, idx + 1, word))
            return true;
    }

    board[i][j] = temp;

    return false;
}

bool exist(vector<vector<char>> &board, string word)
{
    int rows = board.size(), cols = board[0].size();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (board[i][j] == word[0] &&
                f(rows, cols, board, i, j, 0, word))
                return true;
        }
    }
    return false;
}