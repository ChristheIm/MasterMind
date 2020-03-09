#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "MM_Guess.h"


class Game{
private:
	MM_Guess currGuess;
	MM_Guess secretCode;
	int numGuesses;
	int whitePegs;
	int blackPegs;
	// for advance game feature
	int gameboard[44]{ 0 };


public:
	Game();
	void generateFeedback();
	void playGame();
	void getUserGuess();
	bool isWinner();
	bool outOfGuesses();

	// For advance game feature
	void colorTable();
	void displayUserGuess();

};
#endif