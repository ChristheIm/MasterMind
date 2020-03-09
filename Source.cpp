/*
Kyungchan Im
CST - 210
02/16/2020
Professor Lydia Fritz

	This assignment is the first of a two-part assignment that creates a computer version of the game Mastermind. 
	In this game, there are two players: the codemaker (computer) and the codebreaker (user). 
	The codemaker picks a sequence of four pegs, each one being one of any six colors. 
	The codebreaker then tries to guess the exact positions of the colors in the computer's sequence in as few guesses as possible. 
	After each guess, the codemaker gives feedback of exact and partial matches as described in the rules, below.

	<Mastermind Rules>
	1. For each of the pegs in the guess that is the correct color and in the correct position, the codemaker will give one black peg. 
	2. If a guess scores four black pegs, then the codebreaker has guessed the secret code.
	3. For each of the pegs in the guess that is a correct color in an incorrect position, the codemaker will give one white peg. 
	4. Together, there will be no more than four black and white pegs for each move.
	5. The color sequence can contain pegs of the following colors: red, yellow, green, blue, white, and black. 
	6. A color can be used any number of times in the sequence. All four pegs of the secret sequence will contain a color; no blanks/empties are allowed.
	7. Each guess must consist of four peg colors—no blanks.
	***The codebreaker has 10 guesses to find the secret sequence.

*/
#include <iostream>
#include "MM_Guess.h"
#include "Game.h"

using namespace std;


int main() {

	Game play;
	play.playGame();
	return 0;
}