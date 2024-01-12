# Bugrush
## John Asencio
### Bugrush - A BFS algorithm to solve a game derived from Rush Hour

# Summary of the game
Bugrush is a spin off of the game rush hour. In this game '>' represents the car which you must get all the way 
to the right from following the rules of the game. The rules are '-' and '>' can only move horizontally, and '|' 
can only move vertically. The top row is filled with '-' that are just parked cars and cannot be moved they just
denote the size of the board

# Problems and Solutions
I had a working solution for the game at first. I had a State object which included the board, pointers to parent states 
(which were used for counting moves), and an id. The board was a vector of vector of characters, a 2d board. When I
had my working solution, it was very slow for the bigger boards. One fix I had was to make the 2d board a 1d board with strings.
That significantly improved runtime but it was not fast enough yet. Then I realized I was storing entire states ALONG with ALL 
of the parent states, which was absolutely not necessary. So I switched the visited list to only store the strings that were 
the boards. Since I swiched my boards structure and restructured my program form how it originally was, this means that my
unit tests also had to be changed. They were testing for file input and to track the states of the BFS. However, I did
not have the time to change the tests to work with the new string boards. This is why the tests are there, but currently they 
would not run or compile based on the new current state of the game, but they did serve their purpose for when I needed them.

# How to run and compile
You can compile using g++ -g -Wall -o bugrush bugrush.cpp or simply with make
The Makefile lets you run it make all FILENAME='the name of the bugs file'
Or alternatively you could run ./bugrush 'filename'
For example to see the output of 'some5x7.bugs' in this directory:

make run FILENAME=hw-bugrush/some5x7.bugs OR
./bugrush hw-bugrush/some5x7.bugs


