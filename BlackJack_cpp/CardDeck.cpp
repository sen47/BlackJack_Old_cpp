#include "CardDeck.h"

///////////////////////////////////////////////////
//private
void CardDeck::SwapCard(Card& first, Card& second)
{
	std::swap(first, second);
}

//////////////////////////////////////////////////
//public
CardDeck::CardDeck()
{
	int tmp_suit = 0, tmp_rank = 0;
	for (int i = 0, count = 0; i < static_cast<int>(Suit::SUIT_SIZE); ++i)
	{
		for (int j = 0; j < static_cast<int>(Rank::RANK_SIZE); ++j, ++count)
		{
			deck[count].setSuit(static_cast<Suit>(tmp_suit));
			deck[count].setRank(static_cast<Rank>(tmp_rank));
			++tmp_rank;
		}
		++tmp_suit;
		tmp_rank = 0;
	}

	ShuffleDeck();
	ShuffleDeck();
}

void CardDeck::ShuffleDeck()
{
	int rand_card = rand();
	for (Card& el : deck)
	{
		rand_card = rand() % 52;
		SwapCard(el, deck[rand_card]);
	}
}

void CardDeck::PrintDeck()
{
	for (Card el : deck)
		std::cout << el.GetCard() << std::endl;
}

Card& CardDeck::getFirstCard()
{
	return deck[0];
}