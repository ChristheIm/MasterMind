#include "MM_Guess.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

// Constructor for initializing aGuess[4]{-1}
MM_Guess::MM_Guess()
{
	for (int i = 0; i < 4; i++)
	{
		aGuess[i] = -1;
	}
}

// set a guess depends on the userInput
void MM_Guess::setGuess(int guess_1, int guess_2, int guess_3, int guess_4)
{
	if (isValid(guess_1)) {
		aGuess[0] = guess_1;
	}
	if (isValid(guess_2)) {
		aGuess[1] = guess_2;
	}
	if (isValid(guess_3)) {
		aGuess[2] = guess_3;
	}
	if (isValid(guess_4)) {
		aGuess[3] = guess_4;
	}
}

// using random function to create secret code
void MM_Guess::setMaster()
{
	srand(time(0));
	for (size_t i = 0; i < 4; i++)
	{
		aGuess[i] = rand() % 8;
	}
}

// checking for number range between 0-7
bool MM_Guess::isValid(int number) 
{
	if (number > 7 || number < 0) {
		std::cout << "Invalid Number!" << std::endl;
		return false;
	}
	else { return true; }
}

// operator for returning aGuess[index] values
int MM_Guess::operator[](int index)
{
	return aGuess[index];
}
