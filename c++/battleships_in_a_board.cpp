#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int countBattleships(vector<vector<char>>& board) {
    int count = 0;
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (board[i][j] == '.' || (i > 0 && board[i-1][j] == 'X') || (j > 0 && board[i][j-1] == 'X')) {
          continue;
        }
        count++;
      }
    }
    return count;
  }
};

int main() {
  vector<vector<char> > board(3, vector<char>(4, '.'));
  board[0][0] = 'X';
  board[0][3] = 'X';
  board[1][3] = 'X';
  board[2][3] = 'X';
  Solution s;
  int count = s.countBattleships(board);
  cout << count << endl;
  return 0;
}
