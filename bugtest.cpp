#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <fstream>
#include "bugrush.h"

using namespace std;

#define ASSERT_EQUAL_BOARDS(expected, actual)           \
    if (areEqual(expected, actual)) {                   \
        cout << "PASSED: " << __FUNCTION__ << endl;     \
    } else {                                            \
        cerr << "FAILED: " << __FUNCTION__ << endl;     \
    }

int display_board(const vector<vector<char> > board) {

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            cout << board[i][j];
        }
        cout << "\n";
    }

    return 0;
}

bool areEqual(const vector<vector<char> >& vect1, const vector<vector<char> >& vect2) {
    
    display_board(vect1);
    cout << "\n";
    display_board(vect2);

    if (vect1.size() != vect2.size()) {
        return false;
    }

   for (int i = 0; i < vect1.size(); i++) {
        for(int j = 0; j < vect1[i].size(); j++) {
            if (vect1[i][j] != vect2[i][j]) {
                return false;
            }        
        }
    }

    return true;
}




//testing if the file is being read in right
int testFileRead(const string& file) {

    vector<vector<char> > dumb2x2;
    vector<char> row1;
    row1.push_back('-');
    row1.push_back('-');
    vector<char> row2;
    row2.push_back(' ');
    row2.push_back('-');
    vector<char> row3;
    row3.push_back('>');
    row3.push_back('|');
    dumb2x2.push_back(row1); 
    dumb2x2.push_back(row2); 
    dumb2x2.push_back(row3); 

    vector<vector<char> > input;

    input = init_state(file);
    ASSERT_EQUAL_BOARDS(dumb2x2, input);
   return 0;
}

int a() {

    return 0;
}


// the tests must be called as follows
// ./bugtest FILE_NAME TEST_NAME 
int main(int argc, char* argv[]) {
    vector<string> tests;

    if (argc == 3)  {  
        tests.push_back("testFileRead");
    } else {
        for (int i = 2; i < argc; ++i) {
            tests.push_back(argv[i]);
        }
    }

     for (const string& test : tests) {
        if (test == "testFileRead") {
            testFileRead(argv[1]);
        } else if (test == "a") {
            a();
        }
     }
     return 0;
}
