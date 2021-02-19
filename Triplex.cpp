#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
	// Print welcome messages to the terminal
	std::cout << "You are a secret agent breaking into a level " << Difficulty << " secure room...\n";
	std::cout << "Enter the correct code to continue...\n";
	std::cout << "There are 3 numbers in the code\n";
	std::cout << "Enter the correct code to continue...\n\n";
	return;
}

bool PlayGame(int Difficulty)
{
	PrintIntroduction(Difficulty);

	// Declare 3 number code
	const int CodeA = rand() % Difficulty + Difficulty;
	const int CodeB = rand() % Difficulty + Difficulty;
	const int CodeC = rand() % Difficulty + Difficulty;
	int GuessA, GuessB, GuessC;
	int GuessSum;
	int GuessProduct;

	const int CodeSum = CodeA + CodeB + CodeC;
	const int CodeProduct = CodeA * CodeB * CodeC;

	// Print sum and product to the terminal
	std::cout << "The codes add-up to: " << CodeSum;
	std::cout << "\nThe codes multiply to: " << CodeProduct;
	std::cout << "\nNumber entered is: ";
	std::cin >> GuessA >> GuessB >> GuessC;
	std::cout << "\nYou entered: " << GuessA << GuessB << GuessC;

	// Adding and multiplying the guesses
	GuessSum = GuessA + GuessB + GuessC;
	GuessProduct = GuessA * GuessB * GuessC;

	// Check if player guess is correct
	if (GuessSum == CodeSum && GuessProduct == CodeProduct)
	{
		std::cout << "\n\nYou win!\n\n";
		return true;
	}
	else
	{
		std::cout << "\n\nWrong! You lose dumb dumb!\n\n";
	}
	return false;
}

int	main()
{
	srand(time(NULL));
	int LevelDifficulty = 1;
	const int MaxDifficulty = 5;
	
	while (LevelDifficulty <= MaxDifficulty)
	{
		bool bLevelComplete = PlayGame(LevelDifficulty);
		std::cin.clear(); // clear any errors
		std::cin.ignore(); // ignore the errors

		if (bLevelComplete)
		{
			std::cout << "Moving on to the next level\n";
			++LevelDifficulty;
			// increase the level difficulty
		}
		else
		{
			std::cout << "Repeat the level! Try again lol!!\n";
		}
	}

	std::cout << "Congratulation! You won the game!\n";

	return 0;
}