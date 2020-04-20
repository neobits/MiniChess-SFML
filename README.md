# MiniChess
It's a simple 2D graphical approach of the common chess game built 
upon Simple and Fast Multimedia Library (SFML).

## Dev
The system loads the chess pieces for the two players and initializes the board 
with an input string. It's built with a standard game engine derived from the SFML.

## Uses
To initialize the board dinamically, a the input `string` is written under algebraic 
notation `"rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR"`, 

## Further Dev
Many ideas come to expand the system and are planned:
- Make a turn based chess game for two human players using the algebraic notation;
- Implementing a simple LAN/Socket game session for connect a remote player;
- Develop an evaluation method to create an iA machine
- Minor improvements to load random graphic tiles and more style pieces to the game.

## Tools used
- [SFML 2.5.1 64-bit](https://www.sfml-dev.org/download/sfml/2.5.1/)
- MS Visual Studio Community 2017
