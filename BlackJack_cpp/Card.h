#pragma once
#include<string>
#include<stdexcept>

enum Suit
{
	SPADES, HEARTS, DIAMONDS, CLUBS, SUIT_SIZE
};

enum Rank
{
	TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE, RANK_SIZE
};

class Card
{
public:
	Card(const Suit suit = static_cast<Suit>(0), const Rank rank = static_cast<Rank>(0));
	std::string GetCard();
	int GetCardValue();
	void setRank(const Rank rank);
	void setSuit(const Suit suit);

private:
	Suit m_suit;
	Rank m_rank;
};