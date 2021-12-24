#include "Card.h"

////////////////////////////////////////////
//public
Card::Card(const Suit suit, const Rank rank) 
	:m_suit{ suit }, m_rank{ rank }{};

std::string Card::GetCard()
{
	std::string card_name;
	switch (m_rank)
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

	switch (m_suit)
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

	return card_name + " (" + std::to_string(GetCardValue()) + ')';
}

int Card::GetCardValue()
{
	switch (m_rank)
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
		throw std::runtime_error("Unknown value of Rank");
		break;
	}
}

void Card::setRank(const Rank rank)
{
	m_rank = rank;
}

void Card::setSuit(const Suit suit)
{
	m_suit = suit;
}
