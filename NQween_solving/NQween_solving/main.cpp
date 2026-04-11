#include"NQween.h"
#include<iostream>
#include<chrono>



void printResult(const vector<vector<string>>& res) {
    int count = 1;

    for (const auto& board : res) {
        cout << "解 " << count++ << ":\n";
        for (const auto& row : board) {
            cout << row << endl;
        }
        cout << "------------------\n";
    }
}

int main() {
    
    Solution s;
    clock_t start;
    int n;
    cout << "请输入 N（棋盘大小）: ";
    cin >> n;

    vector<vector<string>> res = s.solveNQueens(n);

    cout << "一共有 " << res.size() << " 种解法\n\n";

    printResult(res);

    return 0;
}