//John Asencio
//This holds the functions for the program to run
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <unordered_set>
#include <fstream>

using namespace std;

//class state holds board and board dimension
class State {

    public:
        //data members
        State * parent = NULL;
        string board; 
        int id = 0;   
        int board_dim = 0;

        State(){}

        //copy constructor for State object
        State(const State& obj) {
            id = obj.id;

            board = obj.board;
            board_dim = obj.board_dim;

            if (obj.parent)
                parent = new State(*obj.parent);
        }

        //return a list of possible moves
        vector<string> valid_moves() {
            vector<string> moves;
            int size = board.size();

            //loops through board checking each index to see if there is a valid move
            //depending on board piece
            for (int i = board_dim; i < size; i++) {
                if (board[i] == '|') {
                    if (board[i-board_dim] == ' ') {
                        string temp;
                        temp = board;
                        temp[i-board_dim] = '|';
                        temp[i] = ' ';
                        moves.push_back(temp);
                    }
                    if (board[i+board_dim] == ' ') {
                        string temp;
                        temp = board;
                        temp[i+board_dim] = '|';
                        temp[i] = ' ';
                        moves.push_back(temp);
                    }
                }

                if (board[i] == '>') {
                    if (i + 1 < size && board[i + 1] == ' ' && (i + 1) % board_dim != 0) //|| (i+2)%board_dim == 0))
                    {
                        string temp;
                        temp = board;
                        temp[i] = ' ';
                        temp[i+1] = '>';
                        moves.push_back(temp);
                    }
                    if (board[i-1] == ' ' && (i)%board_dim != 0)
                    {
                        string temp;
                        temp = board;
                        temp[i] = ' ';
                        temp[i-1] = '>';
                        moves.push_back(temp);
                    }
                }

                if (board[i] == '-') {
                    if (i + 1 < size && board[i + 1] == ' ' && (i + 1) % board_dim != 0)// || (i+2)%board_dim == 0))
                    {
                        string temp;
                        temp = board;
                        temp[i] = ' ';
                        temp[i+1] = '-';
                        moves.push_back(temp);
                    }
                    if (board[i-1] == ' ' && (i)%board_dim != 0)
                    {
                        string temp;
                        temp = board;
                        temp[i] = ' ';
                        temp[i-1] = '-';
                        moves.push_back(temp);
                    }
                }
            }

            return moves;
        }           

        //makes the move on the board, just sets the current board to the input states board
        int make_move(string m) {
            board = m;
            return 1;
        }

        //returns the length of the list of parents, which would be the number of moves - recursively
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

        //code to read in board from ext file, 
        //code inspired by https://www.tutorialspoint.com/read-file-line-by-line-using-cplusplus 
        int init_state(const string& file) {

            ifstream input_file(file);

            if (!input_file.is_open()) {
                cerr << "Error: Opening file no work" << endl;
                return 0;
            }

            string line;

            while (getline(input_file, line)) {
                board_dim = 0;
                for (char c : line) {
                    board += c;
                    board_dim += 1;
                }
            }

            input_file.close();

            return 0;  

        }

        bool operator==(const State& other) const {
            if (board == other.board && id == other.id)
                return true;
            return false;
        }
};

//function to check if the puzzle is solved
bool is_solved(const State& state) {
    int board_len = state.board.size();
    for (int i = state.board_dim-1; i < board_len; i+=state.board_dim) {
        if (state.board[i] == '>') {
            return true;
        }
    }
    return false;  
}

//BFS algorithm to solve the puzzle
int solve_puzzle(const State& initialState) {

    //starting state
    State start(initialState);
    //list of visited states (stopping condition)
    unordered_set<string> visited;

    visited.insert(start.board);

    //queue of states to visit
    queue<State> q;

    q.push(start);

    while (!q.empty()) {
        State s(q.front());
        q.pop();

        vector<string> ms = s.valid_moves();
        for (string m : ms) {
            State c(s);
            c.make_move(m);
            if (visited.find(c.board) != visited.end()) {
                continue;
            }
            if (is_solved(c)) {
                return c.move_len();
            }
            else { 
                c.parent = new State(c);
                visited.insert(c.board);
                q.push(c);
            }
        }

    }
    return -1;
}


