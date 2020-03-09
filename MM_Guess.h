#ifndef MM_GUESS_H
#define MM_GUESS_H
#include <iostream>
class MM_Guess
{
private:
	int aGuess[4];
public:
	MM_Guess();
	void setGuess(int guess_1, int guess_2, int guess_3, int guess_4);
	void setMaster();
	bool isValid(int number);
	int operator[](int size);

};

#endif

