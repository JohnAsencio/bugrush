#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <fstream>

using namespace std;

// Define the puzzle state structure
class State {

    public:
        // Data members
        vector<vector<char> > board;      
        int moves;      
    //    State * parent;

        //Return a list of possible moves
        vector<vector<char> > valid_moves() {
            vector<vector<char> > temp;
            temp[0].push_back('d');
            return temp;
        }           

        int make_move(vector<char> m) {
            return 0;
        }

        // Added overloaded operator in order to fix map error when inserting State
        bool operator<(const State& other) const {
            return moves < other.moves;
        }
};

// Function to check if the puzzle is solved
bool is_solved(const State& state) {
    int board_len = state.board[0].size();
    for (int i = 0; i < state.board.size(); i++) {
        if (state.board[i][board_len] == '>') {
            return true;
        }
    }
    return false;  
}

// Function to generate possible moves
vector<State> generate_moves(const State& state) {
    vector<State> nextStates;
    
    // Implement logic to generate possible moves from the current state.
    
    return nextStates;
}

// BFS algorithm to solve the puzzle
int solve_puzzle(const State& initialState) {

    State start = initialState;
   // start.parent = NULL;
    map<State, bool> visited;

    //visited.insert(pair<State, bool>(start, true));   

    queue<State> q;

    q.push(start);

    while (!q.empty()) {
        State s = q.front();
        q.pop();

        vector<vector<char> > ms = s.valid_moves();
        State c = s;
        for (vector<char> m : ms) {
            c.make_move(m);

            if (is_solved(c)) {
                return m.size();
            }

           // if (visited[c] == true) {
             //   continue;
           // }
        }

     //   c.parent = &s;
       // visited.insert(make_pair(c, true));   
        q.push(c);
    }
    //start.moved = -1;


    /*
    queue<State> q;
    map<vector<vector<char> >, bool> visited;
    vector<vector<char> > start = initialState.board;
    
    q.push(initialState);
    visited[start] = true;
    
    while (!q.empty()) {
        State current = q.front();
        q.pop();
        
        vector<State> nextStates = generateMoves(current);
        for (const State& nextState : nextStates) {
                // Make the child.
                c = copy(s)
                c.move(m)

                // Found a solution. Reconstruct and return it.
                if (isSolved(current)) {
            // Puzzle solved, return the number of moves
            return current.moves;
        }

                // Don't re-expand a closed state.
                h = hash(c)
                if h in visited:
                    continue
                
                // Expand and enqueue this child.
                c.parent = s
                c.moved = m
                visited.add(h)
                q.appendleft(c)
        }
        Generate possible moves and add them to the queue if not visited
        vector<State> nextStates = generateMoves(current);
        for (const State& nextState : nextStates) {
            // Serialize the state into a string for uniqueness
         //   string stateString =  
            
            if (visited[stateString]) {
                continue;
            }
        }
    }
*/
    // If the loop completes without finding a solution, return -1
    return -1;

}

vector<vector<char> > init_state(const string& file) {
    vector<vector<char> > board;

    ifstream inputFile(file);

    if (!inputFile.is_open()) {
        cerr << "Error: Opening file no work" << endl;
        return board;
    }

    string line;

    while (getline(inputFile, line)) {
        vector<char> row;
        for (char c : line) {
            row.push_back(c);
        }
        board.push_back(row);
    }

    inputFile.close();

    return board;  
    
}