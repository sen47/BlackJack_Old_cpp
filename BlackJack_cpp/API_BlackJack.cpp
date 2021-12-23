#include "API_BlackJack.h"
/////////////////////////////////////////////////
//private
std::string API_BlackJack::WhoNowMove(const WhoMove currentMove)
{
	switch
	{
	case Player:
		return "Player";
	case Dealler:
		return "Dealler";
	}
}

/////////////////////////////////////////////////
//player
API_BlackJack::Player::Player()
	:m_score{ 0 } {};

void API_BlackJack::Player::addCard(Card* const card)
{
	m_cards.emplace_back(card);
	m_score += card->GetCardValue();
}

Card& API_BlackJack::Player::operator[](const int index)
{
	return *m_cards[index];
}

void API_BlackJack::Player::printCard()
{
	for (Card* el : m_cards)
		std::cout << '\n' << el->GetCard() << " (" << el->GetCardValue() << ')';
	std::cout << "\nScore is " << m_score;
}

/////////////////////////////////////////////////
//public
API_BlackJack::API_BlackJack()
{
}

int API_BlackJack::PlayerAnswer()
{
	int answer;
	while (true)
	{
		answer = Check<int>::checkInput("\n1 - to hit, 2 - to stand, 0 - to exit");
		if (answer >= Exit && answer < MaxAction)
			return answer;
		else
			std::cout << "\nUnvaliable value, try again";
	}
}

bool API_BlackJack::Play()
{
	Player player, dealer;
	Card* ptr_currentCard = &deck.getFirstCard();

	int start_card = 2;
	for (int i = 0; i < start_card; ++i, ++ptr_currentCard)
	{
		dealer.addCard(ptr_currentCard);
	}

	for (int i = 0; i < start_card; ++i, ++ptr_currentCard)
	{
		player.addCard(ptr_currentCard);
	}

	WhoMove currentMove = PlayerMove;
	int player_answer;
	do
	{
		switch (currentMove)
		{
		case PlayerMove:
			std::cout << "Dialler have " << dealer[0].GetCard() << ", and one unknown.";
			player.printCard();
			if (player.m_score > 21)
				return false;
			player_answer = PlayerAnswer();
			if (player_answer == Hit)
			{
				player.addCard(ptr_currentCard);
				system("cls");
			}
		case DeallerMove:

		}
		
		std::cout << "\nDialeer card is:\n";
		for (Card* el : cards_dialler)
			std::cout << el->GetCard() << '\n';
		std::cout << "Score is " << score_dealler << std::endl;

		if (score_dealler > 21) return true;
		if (score_dealler >= 17) break;

		cards_dialler.emplace_back(ptr_currentCard);
		score_dealler += ptr_currentCard->GetCardValue();
		++ptr_currentCard;
		

		

		
		
		////Quick exit
		//if (player_answer == static_cast<int>(Exit));
		//{
		//	std::cout << "\nBye, bye chicken!";
		//	std::exit(0);
		//}

		

	} while (currentMove == Player);

	while (true)
	{
		
	}

	return (21 - score_player) < (21 - score_dealler);
}
