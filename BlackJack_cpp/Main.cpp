#include<ctime>
#include"API_BlackJack.h"
#include"CardDeck.h"

#define DEBUG

#ifdef DEBUG
#define NL std::cout<<std::endl;
#endif // DEBUG

int main()
{
	srand(static_cast<size_t>(time(NULL)));

	API_BlackJack blackJack;

	if (blackJack.Play())
	{
		std::cout << "\nCongratulations, you win!\n";
	}
	else
	{
		std::cout << "\nYou lose, Jonah!\n";
	}

	return 0;
}