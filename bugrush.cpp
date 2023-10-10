#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <fstream>

using namespace std;

// Define the puzzle state structure
struct State {
    vector<vector<char> > board;  // The game board
    int redCarX;        // Position of the red car (the one to be moved out)
    int moves;                   // Number of moves to reach this state
};

// Function to check if the puzzle is solved
bool isSolved(const State& state) {
    // Define your puzzle solved condition here (e.g., red car is at the exit).
    return false;  // Modify this condition accordingly.
}

// Function to generate possible moves
vector<State> generateMoves(const State& state) {
    vector<State> nextStates;
    
    // Implement logic to generate possible moves from the current state.
    
    return nextStates;
}

// BFS algorithm to solve the puzzle
int solvePuzzle(const State& initialState) {
    queue<State> q;
    map<string, bool> visited;
    
    q.push(initialState);
    //visited[/* Serialize the initial state into a string */] = true;
    
    while (!q.empty()) {
        State current = q.front();
        q.pop();
        
        if (isSolved(current)) {
            // Puzzle solved, return the number of moves
            return current.moves;
        }
        
      /*  // Generate possible moves and add them to the queue if not visited
        vector<State> nextStates = generateMoves(current);
        for (const State& nextState : nextStates) {
            // Serialize the state into a string for uniqueness
            string stateString = /* Serialize the state 
            
            if (!visited[stateString]) {
                q.push(nextState);
                visited[stateString] = true;
            }
        }
    }
    */
    // If the loop completes without finding a solution, return -1
    return -1;
}
}

vector<vector<char> > initState(const string& file) {
    vector<vector<char> > board;

    ifstream inputFile(file);

    if (!inputFile.is_open()) {
        cerr << "Error: Opening file no work" << endl;
        return board;
    }

    string line;

    while (getline(inputFile, line))
    {
        vector<char> row;
        for (char c : line) {
            row.push_back(c);
        }
        board.push_back(row);
    }

    inputFile.close();

    return board;  
    
}



int main(int argc, char** argv) {
    // Initialize the puzzle state, set up the initial board and positions.
    State initialState;

    initialState.board = initState(argv[1]);
    // Populate initialState.board and other fields accordingly.

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << initialState.board[i][j];
        }
        cout << "\n";
    }
    
   /* int moves = solvePuzzle(initialState);
    
    if (moves != -1) {
        cout << "The puzzle is solved in " << moves << " moves." << endl;
    } else {
        cout << "No solution found." << endl;
    }
    */
    return 0;
}


