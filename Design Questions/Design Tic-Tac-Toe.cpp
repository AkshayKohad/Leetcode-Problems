#include <vector>
using namespace std;

class TicTacToe {
public:
    vector<vector<int>> board;
    int board_sz;

    TicTacToe(int n) {
        board.assign(n, vector<int>(n, 0));
        board_sz = n;
    }
    
    bool check_winner(int player, int row, int col){
        int n = board_sz;
        
        // Check Horizontal 
        bool win = true;
        for(int i = 0; i < n; i++) {
            if(board[row][i] != player){
                win = false;
                break;
            }
        }
        if(win) return true;
        
        // Check Vertical
        win = true;
        for(int i = 0; i < n; i++) {
            if(board[i][col] != player){
                win = false;
                break;
            }
        }
        if(win) return true;
        
        // Check Main Diagonal
        if(row == col){
            win = true;
            for(int i = 0; i < n; i++) {
                if(board[i][i] != player){
                    win = false;
                    break;
                }
            }
            if(win) return true;
        }
        
        // Check Anti-Diagonal
        if(row + col == n - 1){
            win = true;
            for(int i = 0; i < n; i++) {
                if(board[i][n - 1 - i] != player){
                    win = false;
                    break;
                }
            }
            if(win) return true;
        }
        
        return false;
    }
    
    int move(int row, int col, int player) {
        
        board[row][col] = player;
        if(check_winner(player, row, col)) return player;
        return 0;
    }
};
