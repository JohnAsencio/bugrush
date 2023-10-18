#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <unordered_set>
#include <fstream>

using namespace std;

// Define the puzzle state structure
class State {

    public:
        // Data members
        State * parent = NULL;
        vector<vector<char> > board;      
        int moves = 0;          

        State(){}

        State(const State& obj) {
            moves = obj.moves;

            for (int i = 0; i < obj.board.size(); i++)
            {
                board.push_back(obj.board[i]);
            }
            
            if (obj.parent)
                parent = new State(*obj.parent);
        }

        //Return a list of possible moves
        vector<State> valid_moves() {
            vector<State> moves;
            int rows = board.size();
            int cols = board[0].size();

            for (int i = 1; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (board[i][j] == '>') {
                        if (j < cols-1 && board[i][j + 1] == ' ') {
                            State moveState = *this;  
                            swap(moveState.board[i][j], moveState.board[i][j + 1]);
                            moves.push_back(moveState);
                        }
                        if (j > 0 && board[i][j-1] == ' ') {
                            State moveState = *this;  
                            swap(moveState.board[i][j], moveState.board[i][j - 1]);
                            moves.push_back(moveState);
                            }
                    }

                    if (board[i][j] == '-') {
                        if (j < cols-1 && board[i][j + 1] == ' ') {
                            State moveState = *this;  
                            swap(moveState.board[i][j], moveState.board[i][j + 1]);
                            moves.push_back(moveState);
                        }
                        if (j > 0 && board[i][j-1] == ' ') {
                            State moveState = *this;  // Create a copy of the current state
                            swap(moveState.board[i][j], moveState.board[i][j - 1]);
                            moves.push_back(moveState);
                            }
                    }
                    if (board[i][j] == '|') {
                        if (i < rows-1 && board[i+1][j] == ' ') {
                            State moveState = *this;  
                            swap(moveState.board[i][j], moveState.board[i+1][j]);
                            moves.push_back(moveState);
                        }
                        if (i > 1 && board[i-1][j] == ' ') {
                            State moveState = *this;  
                            swap(moveState.board[i][j], moveState.board[i-1][j]);
                            moves.push_back(moveState);
                        }
                    }
            
                }
            }

            return moves;
        }           

        //makes the move on the board, just sets the current board to the input states board
        int make_move(State m) {
            board = m.board;
            return 1;
        }

        //returns the length of the list of parents, which would be the number of moves
        int move_len(){
            if (!parent)
                return 0;
            return move_len(parent)+1;
        }
        int move_len(State * head){
            if (!head)
                return 0;
            return move_len(head->parent)+1;
        }

        // Added overloaded operator in order to fix map error when inserting State
        bool operator<(const State& other) const {
            return moves < other.moves;
        }

        bool operator==(const State& other) const {
            if (board == other.board && moves == other.moves)
                return true;
            return false;
        }
};

//Class for unordered_set to hash State objects
class Hash{
    public:
        size_t operator()(const State& s) const {
            return hash<int>()(s.moves) << 1; 
        }
};

// Function to check if the puzzle is solved
bool is_solved(const State& state) {
    int board_len = state.board[0].size()-1;
    for (int i = 0; i < state.board.size(); i++) {
        if (state.board[i][board_len] == '>') {
            return true;
        }
    }
    return false;  
}


// BFS algorithm to solve the puzzle
int solve_puzzle(const State& initialState) {

//    vector<State> solved;

    State start(initialState);
    unordered_set<State, Hash> visited;

    visited.insert(start);

    queue<State> q;

    q.push(start);

    while (!q.empty()) {
        State s(q.front());
        q.pop();

        vector<State> ms = s.valid_moves();
        for (State m : ms) {
            State c(s);
            c.make_move(m);
            if (visited.find(c) != visited.end()) {
                continue;
            }
            if (is_solved(c)) {
                //solved.push_back(c);
                return c.move_len();
            }
            else { 
                c.parent = new State(c);
                visited.insert(c);
                q.push(c);
            }
        }

    }

//    if (solved.empty())
//        return -1;
  /*  int min = 1000;

    for (int i = 0; i < solved.size(); i++)
    {
        if (solved[i].move_len() < min)
        {
            min = solved[i].move_len();
        }
    }
*/
    return 0;
}


//code to read in board from ext file, 
//code inspired by https://www.tutorialspoint.com/read-file-line-by-line-using-cplusplus 
vector<vector<char> > init_state(const string& file) {
    vector<vector<char> > board;

    ifstream input_file(file);

    if (!input_file.is_open()) {
        cerr << "Error: Opening file no work" << endl;
        return board;
    }

    string line;

    while (getline(input_file, line)) {
        vector<char> row;
        for (char c : line) {
            row.push_back(c);
        }
        board.push_back(row);
    }

    input_file.close();

    return board;  
    
}
