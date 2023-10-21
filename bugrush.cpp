//John Asencio
//Bugrush AI using BFS
#include "bugrush.h"

int main(int argc, char** argv) {
    
    State initialState;

    //initialize the starting board
    initialState.init_state(argv[1]);

    int moves = solve_puzzle(initialState);
    
    if (moves != -1) {
        cout << moves << endl;
    } else {
        cout << "No solution found." << endl;
    }
    
    return 0;
}


