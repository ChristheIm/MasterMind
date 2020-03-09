#include "Game.h"
#include <array>

Game::Game()
{
	secretCode.setMaster();
	numGuesses = 1;
	whitePegs = 0;
	blackPegs = 0;

}

void Game::generateFeedback()
{

	int user_colors[8]{ 0 };
	int secretCode_colors[8]{ 0 };

	// counting how many colors are in the secretCode and user_guess
	for (size_t i = 0; i < 4; i++)

	{
		user_colors[currGuess[i]]++;
		secretCode_colors[secretCode[i]]++;
	}

	
	//// Display user_color array
	//std::cout << "User Guess Array: ";
	//for (size_t i = 0; i < 8; i++)
	//{
	//	std::cout << user_colors[i] << " ";
	//}
	//std::cout << std::endl;
	//// Display secretCode array
	//std::cout << "SecretCode Array: ";
	//for (size_t i = 0; i < 8; i++)
	//{
	//	std::cout << secretCode_colors[i] << " ";
	//}
	//std::cout << std::endl;
	


	// counting black pegs
	for (size_t i = 0; i < 4; i++)
	{
		if (secretCode[i] == currGuess[i]) {
			blackPegs++;
		}

	}

	// counting white pegs
	int sumWhite = 0;
	int min_num = 0;
	for (size_t i = 0; i < 8; i++)
	{
		if (user_colors[i] > secretCode_colors[i]) 
		{
			min_num = secretCode_colors[i];
		}
		else
		{
			min_num = user_colors[i];
		}
		sumWhite = sumWhite + min_num;
	}
	whitePegs = sumWhite - blackPegs;

	
	// displaying secret code
	std::cout << "secretCode: ";
	for (size_t i = 0; i < 4; i++)
	{
		std::cout << secretCode[i];
	}
	std::cout << std::endl;

	// displaying white pegs and black pegs
	for (size_t i = 0; i < 4; i++)
	{
		gameboard[i] = currGuess[i];
	}
	colorTable();
	displayUserGuess();
	

}

void Game::playGame()
{	

	colorTable();
	do {
		
		secretCode;
		getUserGuess();
		std::cout << std::string(50, '\n');
		generateFeedback();
		if (isWinner()) {
			std::cout << "You won!" << std::endl;
			break;
		}
		else {
			std::cout << "[[ Wrong ]]" << std::endl;
			std::cout << std::endl;
			numGuesses++;
		}
		blackPegs = 0;
		whitePegs = 0;
	} while (!outOfGuesses());

}

void Game::getUserGuess()
{
	std::array<int, 4> guesses;
	while (true)
	{
		bool ok = true;
		std::cout << "Type 4 colors that you want to check: ";
		for (auto& guess : guesses)
		{
			std::cin >> guess;
			if (!std::cin // check a valid number was entered
				|| guess < 0 || guess > 8)
			{
				ok = false;
				break;
			}
		}
		if (ok)
		{
			break;
		}
		std::cin.clear(); // clear error flags
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard the rest of the line
		std::cout << "Please enter integers between 0 and 8\n";
	}
	for (size_t i = 0; i < 4; i++)
	{
		gameboard[numGuesses * 4 + i] = guesses[i];
	}
	currGuess.setGuess(guesses[0], guesses[1], guesses[2], guesses[3]);
}

bool Game::isWinner()
{
	// If black pegs count as 4 then return True
	if (blackPegs == 4) {
		return true;
	}
	else {
		return false;
	}
}

bool Game::outOfGuesses()
{
	if (numGuesses > 10) {
		std::cout << "Sorry! Out of guesses! Try new game!" << std::endl;
		return true;
	}
	else {
		return false;
	}
}


// This code is for displaying colors corresponind with numbers
void Game::colorTable()
{
	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "|  Hello! Welcome to Kyungchan's MasterMind Game!  |" << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "| The purpose of the game is to find secret code!  |" << std::endl;
	std::cout << "| Guess four colors and find the exact colors with |" << std::endl;
	std::cout << "| exact positions				   |" << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "|Type the number that fits to your guess!	   |" << std::endl;
	std::cout << "|0 = Red		1 = Green                  |" << std::endl;
	std::cout << "|2 = Blue		3 = Yellow                 |" << std::endl;
	std::cout << "|4 = Brown		5 = Orange                 |" << std::endl;
	std::cout << "|6 = Black		7 = White                  |" << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
}

void Game::displayUserGuess() 
{

	// displaying user guess code
	std::cout << "Your Guess: " << std::endl;
	
	std::cout << "|" << gameboard[40] << "|" << gameboard[41] << "|" << gameboard[42] << "|" << gameboard[43] << "|    White Pegs: " << whitePegs << std::endl;
	std::cout << "|" << gameboard[36] << "|" << gameboard[37] << "|" << gameboard[38] << "|" << gameboard[39] << "|    Black Pegs: " << blackPegs << std::endl;
	std::cout << "|" << gameboard[32] << "|" << gameboard[33] << "|" << gameboard[34] << "|" << gameboard[35] << "|" << std::endl;
	std::cout << "|" << gameboard[28] << "|" << gameboard[29] << "|" << gameboard[30] << "|" << gameboard[31] << "|" << std::endl;
	std::cout << "|" << gameboard[24] << "|" << gameboard[25] << "|" << gameboard[26] << "|" << gameboard[27] << "|" << std::endl;
	std::cout << "|" << gameboard[20] << "|" << gameboard[21] << "|" << gameboard[22] << "|" << gameboard[23] << "|" << std::endl;
	std::cout << "|" << gameboard[16] << "|" << gameboard[17] << "|" << gameboard[18] << "|" << gameboard[19] << "|" << std::endl;
	std::cout << "|" << gameboard[12] << "|" << gameboard[13] << "|" << gameboard[14] << "|" << gameboard[15] << "|" << std::endl;
	std::cout << "|" << gameboard[8] << "|" << gameboard[9] << "|" << gameboard[10] << "|" << gameboard[11] << "|" << std::endl;
	std::cout << "|" << gameboard[4] << "|" << gameboard[5] << "|" << gameboard[6] << "|" << gameboard[7] << "|" << std::endl;
	
	
}