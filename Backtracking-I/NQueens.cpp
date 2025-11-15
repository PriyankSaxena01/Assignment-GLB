#include <bits/stdc++.h>
using namespace std;

class NQueens {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> list;
        vector<vector<bool>> board(n, vector<bool>(n, false));
        findQueens(board, 0, list);
        return list;
    }

    void findQueens(vector<vector<bool>>& board, int row, vector<vector<string>>& list) {
        if (row == board.size()) {
            addTo(board, list);
            return;
        }
        for (int j = 0; j < board.size(); j++) {
            if (isSafe(board, row, j)) {
                board[row][j] = true;
                findQueens(board, row + 1, list);
                board[row][j] = false;
            }
        }
    }

    bool isSafe(vector<vector<bool>>& board, int row, int col) {
        for (int i = 0; i <= row; i++) {
            if (board[i][col]) return false;
        }
        int left = min(row, col);
        for (int i = 1; i <= left; i++) {
            if (board[row - i][col - i]) return false;
        }
        int right = min(row, (int)board.size() - col - 1);
        for (int i = 1; i <= right; i++) {
            if (board[row - i][col + i]) return false;
        }
        return true;
    }

    void addTo(vector<vector<bool>>& board, vector<vector<string>>& list) {
        vector<string> row;
        for (int i = 0; i < board.size(); i++) {
            string p = "";
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j]) p += 'Q';
                else p += '.';
            }
            row.push_back(p);
        }
        list.push_back(row);
    }
};

int main() {
    NQueens nq;
    vector<vector<string>> list = nq.solveNQueens(4);
    for (auto& p : list) {
        for (auto& s : p) cout << s << endl;
        cout << endl;
    }
}
