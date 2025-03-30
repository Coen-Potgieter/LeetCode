


#include <vector>
#include <iostream>

using std::vector;

void printBoard(std::vector<std::vector<int>> inp);

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {


        int m = board.size();
        int n = board[0].size();
        std::vector<std::vector<int>> mappings = {
            {-1,-1}, {-1, 0}, {-1, 1},
            {0, -1}, {0, 1},
            {1, -1}, {1, 0}, {1,1}
        };

        std::vector<std::vector<int>> outp;

        for (int row = 0; row < m; row++) {
            std::vector<int> newRow;
            for (int col = 0; col < n; col++) {

                int neighboursAlive = 0;
                for (const std::vector<int>& mapping : mappings) {

                    int checkRow = row + mapping[0];
                    int checkCol = col + mapping[1];

                    if (checkRow < 0 || checkRow >= m || checkCol < 0 || checkCol >= n) continue;

                    neighboursAlive += board[checkRow][checkCol];
                }

                // Rules
                if (board[row][col] == 1) {
                    // 1. Any live cell with fewer than two live neighbors dies as if caused by under-population.
                    if (neighboursAlive < 2) {
                        newRow.push_back(0);
                    }
                    // 3. Any live cell with more than three live neighbors dies, as if by over-population.
                    else if (neighboursAlive > 3) {
                        newRow.push_back(0);
                    } 
                    // 2. Any live cell with two or three live neighbors lives on to the next generation.
                    else {
                        newRow.push_back(1);
                    }


                } else if (neighboursAlive == 3) {
                    // 4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
                    newRow.push_back(1);
                } else {
                    newRow.push_back(0);
                }

            }
            outp.push_back(newRow);


        }


        board = outp;

    }
};

int main() {

    std::vector<std::vector<int>> board = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    printBoard(board);

    Solution mySol;
    mySol.gameOfLife(board);
    
    std::cout << std::endl;
    printBoard(board);

    return 0;
}

void printBoard(std::vector<std::vector<int>> inp) {
    for (int row = 0; row < inp.size(); row++) {
        for (int col = 0; col < inp[row].size(); col++) {
            std::cout << inp[row][col] << ", ";
        }
        std::cout << std::endl;
    }
}
