# fillit
Some kind of Tetris. The goal of this project is to arrange every Tetriminos (a puzzle) with each others in order to make the smallest possible square.

The input of the project is a file with puzzles, each puzzle separeted from another with a new line. The input file can contain from 1 to 26 Tetraminos.

- Precisely 4 lines of 4 characters, each followed by a new line (well... a 4x4 square).
- Each character must be either a block character(’#’ ) or an empty character (’.’).
- Each block of a Tetrimino must touch at least one other block on any of his 4 sides (up, down, left and right).

Valid example: ..##                      Invalid example: #...    
               ..##                                       .#..
               ....                                       .#..
               ....                                       .#..

The program output is the smallest assembled square on the standard output. To identify each Tetrimino in the square solution, a capital letter assigned to each Tetrimino, starting with ’A’ and increasing for each new Tetrimino.

Error management is present.

To play the gamefirst of all you need to compile it.

In the root of repository enter "make" in your terminal, press Enter and then exe named "fillie" will be created. To start write: "./fillit sample.fillit" in the terminal, where sample.fillit is your input file.

