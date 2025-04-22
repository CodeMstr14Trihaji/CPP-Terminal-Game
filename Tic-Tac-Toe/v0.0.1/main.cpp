#include <iostream>
#include <string>
using namespace std;

// membuat class Player
class Player {
private:
    char symbol;
    string name;

public:
    // Constructor, fungsi yang akan langsung berjalan
    Player(char sym = 'X', string n = "Player X") : symbol(sym), name(n) {}

    // Getter methods
    char getSymbol() const { return symbol; }
    string getName() const { return name; }
};

// Board class to manage game board
class Board {
private:
    char grid[3][3];
    int filledCells; // Counter for filled cells
    
public:
    // Constructor to initialize the board
    Board() : filledCells(0) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                grid[i][j] = ' ';
            }
        }
    }

    // fungsi untuk menampilkan gambar papan
    void drawBoard() const {
        cout << "-------------" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "| ";
            for (int j = 0; j < 3; j++) {
                cout << grid[i][j] << " | ";
            }
            cout << endl << "-------------" << endl;
        }
    }

    // fungsi untuk menentukan apakah gerakan yang diinputkan valid atau tidak
    bool isValidMove(int row, int col) const {
        return (row >= 0 && row < 3 && col >= 0 && col < 3 && grid[row][col] == ' ');
    }

    // fungsi untuk membuat gerakan
    void makeMove(int row, int col, char symbol) {
        if (isValidMove(row, col)) {
            grid[row][col] = symbol;
            filledCells++; // Increment counter ketika kotak terisi
        }
    }

    // fungsi untuk menentukan apakah terdapat kondisi 'menang' pada permainan
    bool checkWin(char symbol) const {
        // cek baris
        for (int i = 0; i < 3; i++) {
            if (grid[i][0] == symbol && grid[i][1] == symbol && grid[i][2] == symbol) {
                return true;
            }
        }
        
        // cek kolom
        for (int i = 0; i < 3; i++) {
            if (grid[0][i] == symbol && grid[1][i] == symbol && grid[2][i] == symbol) {
                return true;
            }
        }
        
        // cek diagonalnya juga
        if (grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol) {
            return true;
        }
        if (grid[0][2] == symbol && grid[1][1] == symbol && grid[2][0] == symbol) {
            return true;
        }
        
        return false;
    }

    // fungsi untuk menentukan apakah semua papan sudah terisi
    bool isFull() const {
        return filledCells == 9;
    }
    
    // fungsi untuk mendapatkan petak papan yang sudah terisi
    int getFilledCellsCount() const {
        return filledCells;
    }
};

// Game class to manage the game logic
class TicTacToe {
private:
    Board board;
    Player players[2];
    int currentPlayerIndex;

public:
    // Constructor
    TicTacToe() : currentPlayerIndex(0) {
        players[0] = Player('X', "Player X");
        players[1] = Player('O', "Player O");
    }

    // Method to get the current player
    Player& getCurrentPlayer() {
        return players[currentPlayerIndex];
    }

    // Method to switch turns
    void switchTurn() {
        currentPlayerIndex = (currentPlayerIndex + 1) % 2;
    }

    // Method to play the game
    void play() {
        int row, col;
        cout << "Welcome to Tic-Tac-Toe!" << endl;

        while (!board.isFull()) {
            // Display the board
            board.drawBoard();
            
            Player& currentPlayer = getCurrentPlayer();
            
            // Get valid input
            while (true) {
                cout << currentPlayer.getName() << " (" << currentPlayer.getSymbol() 
                     << "), enter row (1-3) and column (1-3): ";
                cin >> row >> col;
                row--; col--; // Convert to 0-indexed
                
                if (board.isValidMove(row, col)) {
                    break;
                } else {
                    cout << "Invalid move. Try again." << endl;
                }
            }
            
            // Make move
            board.makeMove(row, col, currentPlayer.getSymbol());
            
            // Check for win
            if (board.checkWin(currentPlayer.getSymbol())) {
                board.drawBoard();
                cout << currentPlayer.getName() << " wins!" << endl;
                return;
            }
            
            // Switch turns
            switchTurn();
        }
        
        // Game ended in a draw
        board.drawBoard();
        cout << "It's a draw!" << endl;
    }
};

int main() {
    TicTacToe game;
    
    game.play();
    return 0;
}
