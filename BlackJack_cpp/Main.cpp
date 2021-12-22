#include<iostream>
#include<string>
#include<array>
#include<utility>
#include<ctime>
#include<vector>

#define DEBUG

#ifdef DEBUG
#define NL std::cout<<std::endl;
#endif // DEBUG

enum class Suit
{
	SPADES, HEARTS, DIAMONDS, CLUBS, SUIT_SIZE
};

enum class Rank
{
	TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE, RANK_SIZE
};

enum class Action
{
	EXIT, HIT, STAND
};

struct Card
{
	Suit suit;
	Rank rank;
};

std::string GetCard(const Card& card);
void PrintDeck(const std::array<Card, 52>& deck);
void SwapCard(Card& first, Card& second);
void ShuffleDeck(std::array<Card, 52>& deck);
int GetCardValue(const Card& card);
bool PlayBlackJack(const std::array<Card, 52>& deck);
int PlayerAnswer();

int main()
{
	srand(static_cast<size_t>(time(NULL)));

	std::array<Card, 52>deck;
	int tmp_suit = 0, tmp_rank = 0;

	//Initial deck
	for (int i = 0, count = 0; i < static_cast<int>(Suit::SUIT_SIZE); ++i)
	{
		for (int j = 0; j < static_cast<int>(Rank::RANK_SIZE); ++j, ++count)
		{
			deck[count].suit = static_cast<Suit>(tmp_suit);
			deck[count].rank = static_cast<Rank>(tmp_rank);
			++tmp_rank;
		}
		++tmp_suit;
		tmp_rank = 0;
	}

	ShuffleDeck(deck);
	ShuffleDeck(deck);

	if (PlayBlackJack(deck))
	{
		std::cout << "\nCongratulations, you win!\n";
	}
	else
	{
		std::cout << "\nYou lose, Jonah!\n";
	}

	return 0;
}

std::string GetCard(const Card& card)
{
	std::string card_name;
	switch (card.rank)
	{
	case Rank::TWO:
		card_name += "Two";
		break;
	case Rank::THREE:
		card_name += "Three";
		break;
	case Rank::FOUR:
		card_name += "Four";
		break;
	case Rank::FIVE:
		card_name += "Five";
		break;
	case Rank::SIX:
		card_name += "Six";
		break;
	case Rank::SEVEN:
		card_name += "Seven";
		break;
	case Rank::EIGHT:
		card_name += "Eight";
		break;
	case Rank::NINE:
		card_name += "Nine";
		break;
	case Rank::TEN:
		card_name += "Ten";
		break;
	case Rank::JACK:
		card_name += "Jack";
		break;
	case Rank::QUEEN:
		card_name += "Queen";
		break;
	case Rank::KING:
		card_name += "King";
		break;
	case Rank::ACE:
		card_name += "Ace";
		break;

	default:
		throw("Unknown value of Rank");
		break;
	}

	switch (card.suit)
	{
	case Suit::SPADES:
		card_name += " spades";
		break;
	case Suit::HEARTS:
		card_name += " hearts";
		break;
	case Suit::DIAMONDS:
		card_name += " diamonds";
		break;
	case Suit::CLUBS:
		card_name += " clubs";
		break;

	default:
		throw("Unknown value of Suit");
		break;
	}

	return card_name;
}

void PrintDeck(const std::array<Card, 52>& deck)
{
	for (Card el : deck)
		std::cout << GetCard(el) << std::endl;
}

void SwapCard(Card& first, Card& second)
{
	std::swap(first, second);
}

void ShuffleDeck(std::array<Card, 52>& deck)
{
	int rand_card = rand();
	for (Card& el : deck)
	{
		rand_card = rand() % 52;
		SwapCard(el, deck[rand_card]);
	}
}

int GetCardValue(const Card& card)
{
	switch (card.rank)
	{
	case Rank::TWO:
		return 2;
		break;
	case Rank::THREE:
		return 3;
		break;
	case Rank::FOUR:
		return 4;
		break;
	case Rank::FIVE:
		return 5;
		break;
	case Rank::SIX:
		return 6;
		break;
	case Rank::SEVEN:
		return 7;
		break;
	case Rank::EIGHT:
		return 8;
		break;
	case Rank::NINE:
		return 9;
		break;
	case Rank::TEN:
		return 10;
		break;
	case Rank::JACK:
		return 10;
		break;
	case Rank::QUEEN:
		return 10;
		break;
	case Rank::KING:
		return 10;
		break;
	case Rank::ACE:
		return 11;
		break;

	default:
		throw("Unknown value of Rank");
		break;
	}
}

bool PlayBlackJack(const std::array<Card, 52>& deck)
{
	int score_player = 0, score_ai = 0, start_card = 2;
	std::vector<Card>cards_palyer, cards_ai;
	const Card* ptr_card = &deck[0];

	for (int i = 0; i < start_card; ++i, ++ptr_card)
	{
		score_ai += GetCardValue(*ptr_card);
		cards_ai.emplace_back(*ptr_card);
	}

	for (int i = 0; i < start_card; ++i, ++ptr_card)
	{
		score_player += GetCardValue(*ptr_card);
		cards_palyer.emplace_back(*ptr_card);
	}

	std::cout << "Dialler have " << GetCard(cards_ai[0]) << ", and one unknown.\n";

	int player_answer;
	do
	{
		std::cout << "\nYour card is:\n";
		for (const Card& el : cards_palyer)
			std::cout << GetCard(el) << '\n';
		std::cout << "Score is " << score_player << std::endl;

		if (score_player > 21)
			return false;

		player_answer = PlayerAnswer();

		//Quick exit
		/*if (answer == static_cast<int>(Action::EXIT));
		{
			std::cout << "Bye, bye chicken!\n";
			std::exit(0);
		}*/

		if (player_answer == static_cast<int>(Action::HIT))
		{
			cards_palyer.emplace_back(*ptr_card);
			score_player += GetCardValue(*ptr_card);
			++ptr_card;
		}

	} while (player_answer != static_cast<int>(Action::STAND));

	while (true)
	{
		std::cout << "\nDialeer card is:\n";
		for (const Card& el : cards_ai)
			std::cout << GetCard(el) << '\n';
		std::cout << "Score is " << score_ai << std::endl;

		if (score_ai > 21) return true;
		if (score_ai >= 17) break;

		cards_ai.emplace_back(*ptr_card);
		score_ai += GetCardValue(*ptr_card);
		++ptr_card;
	}

	return (21 - score_player) < (21 - score_ai);
}

int PlayerAnswer()
{
	int answer;
	while (true)
	{
		std::cout << "\n1 - to hit, 2 - to stand, 0 - to exit\nEnter: ";
		std::cin >> answer;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Unvaliable value, try again\n";
		}
		else
		{
			if (answer >= 0 && answer < 3)
				return answer;
			else
				std::cout << "Unvaliable value, try again\n";
		}
	}
}