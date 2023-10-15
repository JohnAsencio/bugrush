#include "bugrush.h"

int main(int argc, char** argv) {
    // Initialize the puzzle state, set up the initial board and positions.
    State initialState;

    // Populate initialState.board and other fields accordingly.
    initialState.board = init_state(argv[1]);

    int moves = solve_puzzle(initialState);
    
    if (moves != -1) {
        cout << "The puzzle is solved in " << moves << " moves." << endl;
    } else {
        cout << "No solution found." << endl;
    }
    
    return 0;
}


