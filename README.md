## Chesstrainer
 a C++ program meant to help you train chess, this is only the bare version of the code,
the program has many features currently as a beginning:
it can:
- create a chess board
- import puzzles from the lichess csv file
- import a beginning position from FEN writing
- create icons based on position of arrays
- features like daily puzzles
- save history, completed puzzles, failed  puzzles

  <img width="738" height="781" alt="image" src="https://github.com/user-attachments/assets/fe2ad7c1-45c6-434f-8989-722da4f9b25b" />


## Week2 
- every move is checked against the chess rules: illegal moves are refused, pinned pieces included
- Check! and Checkmate!
- hints 
- practice one theme (fork, pin, mateIn2...), streak mode, and a timer on every puzzle
- the last move is coloured on the board
- 33 rule tests in `tests/rulest.cpp`

## How to run
Go to the Releases page, download `chesstrainer-v2-linux.tar.gz`, unpack it, and run `./chess` in that folder.

## How to build
You need g++ and make.

make        # builds src/chess
make test   # runs the rule tests
make run    # plays


## Why I built this
as a chess enthusiast and reaching 1000 elo last year, i fell in love with this game, but i found that puzzles are a bit hard to be motivated to do, 
i thus decided to build this engine as a way to reconnect with chess again but also something that'll help me regain what i have forgotten and also improve at chess!



sources:
Codecademy course.
to learn how to  write header files : 
https://www.learncpp.com/cpp-tutorial/header-guards/

how vectors work: 
https://www.w3schools.com/cpp/cpp_vectors.asp
and Codecademy course.


board.cpp and board.h
https://www.chessprogramming.org/Forsyth-Edwards_Notation
https://www.chessprogramming.org/Algebraic_Chess_Notation

https://www.chessprogramming.org/En_passant
https://www.w3schools.com/cpp/cpp_conditions_shorthand.asp

main.cpp: 
https://www.w3schools.com/cpp/cpp_switch.asp
https://www.w3schools.com/cpp/cpp_output.asp

play.h and play.cpp :
https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/
https://www.w3schools.com/cpp/cpp_function_reference.asp
https://en.cppreference.com/w/cpp/string/basic_string/substr


profile.cpp  and profile.h:
https://en.wikipedia.org/wiki/Elo_rating_system#Mathematical_details



puzzle.cpp and puzzle.h: 
https://database.lichess.org/#puzzles
https://www.w3schools.com/cpp/cpp_files.asp
https://www.w3schools.com/cpp/cpp_break.asp

trainer.cpp and trainer.h:
https://en.cppreference.com/w/cpp/chrono/c/time
https://en.cppreference.com/w/cpp/container/vector/erase


rules.cpp and rules.h:
https://www.chess.com/lessons/learn-to-play
https://www.chessprogramming.org/Perft_Results
https://www.learncpp.com/cpp-tutorial/introduction-to-testing-your-code/

util.cpp and util.h:
https://en.cppreference.com/w/cpp/string/basic_string/getline
