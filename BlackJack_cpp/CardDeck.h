#pragma once
#include<iostream>
#include<array>
#include<algorithm>

#include"Card.h"

class CardDeck
{
public:
	//Initial deck
	CardDeck();
	void ShuffleDeck();
	void PrintDeck();
	Card& getFirstCard();

private:
	std::array<Card, 52>deck;

	void SwapCard(Card& first, Card& second);
};