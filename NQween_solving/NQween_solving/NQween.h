#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));

        unordered_set<int> col_set;      // 列
        unordered_set<int> add_set;      // 主对角线 row+col
        unordered_set<int> sub_set;      // 副对角线 row-col

        dfs(res, col_set, add_set, sub_set, n, 0, board);
        return res;
    }

    void dfs(vector<vector<string>>& res,
        unordered_set<int>& col_set,
        unordered_set<int>& add_set,
        unordered_set<int>& sub_set,
        int n, int row,
        vector<string>& board) {

        // 找到一个解
        if (row == n) {
            res.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {

            // 冲突判断
            if (col_set.count(col) ||
                add_set.count(row + col) ||
                sub_set.count(row - col)) {
                continue;
            }

            // 选择
            col_set.insert(col);
            add_set.insert(row + col);
            sub_set.insert(row - col);
            board[row][col] = 'Q';

            // 递归
            dfs(res, col_set, add_set, sub_set, n, row + 1, board);

            // 回溯（撤销）
            col_set.erase(col);
            add_set.erase(row + col);
            sub_set.erase(row - col);
            board[row][col] = '.';
        }
    }
};