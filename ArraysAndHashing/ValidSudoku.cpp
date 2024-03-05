//
// Created by Joel Jose Ginga on 25/02/2024.
//
/**
 * Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
 * 1. Each row must contain the digits 1-9 without repetition.
 * 2. Each column must contain the digits 1-9 without repetition.
 * 3. Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
 *
 * The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 * Example 1:
 * Input: board =
 * [["5","3",".",".","7",".",".",".","."]
 * ,["6",".",".","1","9","5",".",".","."]
 * ,[".","9","8",".",".",".",".","6","."]
 * ,["8",".",".",".","6",".",".",".","3"]
 * ,["4",".",".","8",".","3",".",".","1"]
 * ,["7",".",".",".","2",".",".",".","6"]
 * ,[".","6",".",".",".",".","2","8","."]
 * ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".",".","8",".",".","7","9"]]
 * Output: true
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::vector<std::unordered_set<char>> rows(9);
        std::vector<std::unordered_set<char>> cols(9);
        std::vector<std::unordered_set<char>> boxs(9);

        for(int row = 0 ; row < board.size() ; row++) {
            for(int col = 0 ; col < board[0].size() ; col++){
                if(board[row][col] =='.')
                    continue;

                int quadrant = (row/3) * 3 + col / 3;

                if(rows[row].count(board[row][col]) || cols[col].count(board[row][col]) || boxs[quadrant].count(board[row][col]))
                    return false;

                rows[row].insert(board[row][col]);
                cols[col].insert(board[row][col]);
                boxs[quadrant].insert(board[row][col]);
            }
        }

        return true;
    }
};