#pragma once
#include"CardDeck.h"
#include"Check.h"
#include<vector>

enum Action
{
	Exit, Hit, Stand, MaxAction
};

enum WhoMove
{
	PlayerMove, DeallerMove
};

class API_BlackJack
{
public:
	API_BlackJack();
	int PlayerAnswer();
	bool Play();

private:
	CardDeck deck;

	void printCards(const std::vector<Card*>cards, const WhoMove currentMove);
	std::string WhoNowMove(const WhoMove currentMove);

	class Player
	{
	public:
		Player();
		void addCard(Card* const card);
		Card& operator [](const int index);
		void printCard();

		std::vector<Card*>m_cards;
		int m_score;
	};
};