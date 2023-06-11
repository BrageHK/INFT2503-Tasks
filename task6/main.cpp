#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <functional>

using namespace std;
class ChessBoard;
class ChessBoardPrint;

class ChessBoard {
public:
    enum class Color { WHITE,
        BLACK };

    class Piece {
    public:
        Piece(Color color) : color(color) {}
        virtual ~Piece() {}

        Color color;
        string color_string() const {
            if (color == Color::WHITE)
                return "white";
            else
                return "black";
        }

        /// Return color and type of the chess piece
        virtual string type() const = 0;

        virtual string shortName() const = 0;

        /// Returns true if the given chess piece move is valid
        virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;
    };

    class King : public Piece {
    public:
        King(Color color) : Piece(color) {}

        string type() const override {
            return color_string() + " king";
        }

        string shortName() const override {
            return (color == ChessBoard::Color::WHITE) ? "K" : "k";
        }

        bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
            return abs(from_x - to_x) <= 1 && abs(from_y - to_y) <= 1;
        }
    };

    class Knight : public Piece {
    public:
        Knight(Color color) : Piece(color) {}

        string type() const override {
            return color_string() + " knight";
        }

        string shortName() const override {
            return (color == ChessBoard::Color::WHITE) ? "N" : "n";
        }

        bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
            return (abs(from_x - to_x) == 2 && abs(from_y - to_y) == 1) || (abs(from_x - to_x) == 1 && abs(from_y - to_y) == 2);
        }
    };


    ChessBoard() {
        // Initialize the squares stored in 8 columns and 8 rows:
        squares.resize(8);
        for (auto &square_column : squares)
            square_column.resize(8);
    }

    /// 8x8 squares occupied by 1 or 0 chess pieces
    vector<vector<unique_ptr<Piece>>> squares;

    function<void(const ChessBoard::Piece &piece, const string &from, const string &to)> on_piece_move;
    function<void(const ChessBoard::Piece &piece, const string &square)> on_piece_removed;
    function<void(const ChessBoard::Piece &piece, const string &from, const string &to)> on_piece_move_invalid;
    function<void(const string &square)> on_piece_move_missing;
    function<void(ChessBoard::Color color)> on_lost_game;
    function<void()> printBoard;


    /// Move a chess piece if it is a valid move.
    /// Does not test for check or checkmate.
    bool move_piece(const std::string &from, const std::string &to) {
        int from_x = from[0] - 'a';
        int from_y = stoi(string() + from[1]) - 1;
        int to_x = to[0] - 'a';
        int to_y = stoi(string() + to[1]) - 1;

        auto &piece_from = squares[from_x][from_y];
        if (piece_from) {
            if (piece_from->valid_move(from_x, from_y, to_x, to_y)) {
                on_piece_move(*piece_from, from, to);
                auto &piece_to = squares[to_x][to_y];
                if (piece_to) {
                    if (piece_from->color != piece_to->color) {
                        on_piece_removed(*piece_to, to);
                        if (auto king = dynamic_cast<King *>(piece_to.get()))
                            on_lost_game(king->color);
                    } else {
                        // piece in the from square has the same color as the piece in the to square
                        on_piece_move_invalid(*piece_from, from, to);
                        return false;
                    }
                }
                piece_to = move(piece_from);
                printBoard();
                return true;
            } else {
                on_piece_move_invalid(*piece_from, from, to);
                return false;
            }
        } else {
            on_piece_move_missing(from);
            return false;
        }

    }


};

class ChessBoardPrint {
public:
    ChessBoardPrint(ChessBoard &chessBoard){
        cout << "Welcome to a game of chess." << endl;
        chessBoard.on_lost_game = [](ChessBoard::Color color) {
            string colorString = "White";
            if(ChessBoard::Color::BLACK == color) colorString = "Black";
            cout << colorString << " lost the game!"<< endl;
        };
        chessBoard.on_piece_move = [](const ChessBoard::Piece &piece, const string &from, const string &to){
            cout << piece.type() << " is moving from " << from << " to " << to << "."<< endl;
        };
        chessBoard.on_piece_move_invalid = [](const ChessBoard::Piece &piece, const string &from, const string &to){
            cout << piece.type() << " can not move from " << from << " to " << to << "."<< endl;
        };
        chessBoard.on_piece_removed = [](const ChessBoard::Piece &piece, const string &square){
            cout << piece.type() << " is being removed from " << square << "." << endl;
        };
        chessBoard.on_piece_move_missing = [](const string &square){
            cout << "no piece at " << square << "." << endl;
        };
        chessBoard.printBoard = [&chessBoard](){
            const vector<string> letters = {"a", "b", "c", "d", "e", "f", "g", "h"};
            for(int y = 0; y < chessBoard.squares.size(); y++) {
                cout << y+1;
                for(int x = 0; x < chessBoard.squares.size(); x++) {
                    auto &piece = chessBoard.squares[x][y];
                    if(piece) {
                        cout << " " + piece->shortName();
                    } else {
                        cout << "  ";
                    }
                }
                cout << endl;
            }
            cout << "  ";
            for(int i = 0; i < chessBoard.squares[0].size(); i++)
                cout << letters[i] << " ";
            cout << endl;
        };
    }
};

int main() {
    ChessBoard board;
    ChessBoardPrint draw(board);


    board.squares[4][0] = make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
    board.squares[1][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
    board.squares[6][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

    board.squares[4][7] = make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
    board.squares[1][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
    board.squares[6][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

    cout << "Invalid moves:" << endl;
    board.move_piece("e3", "e2");
    board.move_piece("e1", "e3");
    board.move_piece("b1", "b2");
    cout << endl;

    cout << "A simulated game:" << endl;
    board.move_piece("e1", "e2");

    board.move_piece("g8", "h6");
    board.move_piece("b1", "c3");
    board.move_piece("h6", "g8");
    board.move_piece("c3", "d5");
    board.move_piece("g8", "h6");
    board.move_piece("d5", "f6");
    board.move_piece("h6", "g8");
    board.move_piece("f6", "e8");
}