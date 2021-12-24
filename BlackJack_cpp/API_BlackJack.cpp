#include "API_BlackJack.h"
/////////////////////////////////////////////////
//private
std::string API_BlackJack::getWhoMove(const WhoMove currentMove)
{
	switch(currentMove)
	{
	case PlayerMove:
		return "Player";
	case DeallerMove:
		return "Dealler";
	}
}

/////////////////////////////////////////////////
//player
API_BlackJack::Player::Player()
	:m_score{ 0 } {};

void API_BlackJack::Player::addCard(Card* card)
{
	m_cards.emplace_back(card);
	m_score += card->GetCardValue();
	++card;
}

Card& API_BlackJack::Player::operator[](const int index)
{
	return *m_cards[index];
}

void API_BlackJack::Player::printCard()
{
	for (Card* el : m_cards)
		std::cout << '\n' << el->GetCard();
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
		{
			std::cout << "\nUnvaliable value, try again";
		}
			
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
		std::cout << "Dialler have " << dealer[0].GetCard() << ", and one unknown.";
		std::cout << "\n\n" << getWhoMove(currentMove) << "\'s card is: ";
		player.printCard();
		if (player.m_score > 21)
			return false;
		if (player.m_score == 21)
		{
			currentMove = DeallerMove;
			system("cls");
			break;
		}
		player_answer = PlayerAnswer();
		switch (player_answer)
		{
		case Hit:
			player.addCard(ptr_currentCard);
			system("cls");
			break;
		case Stand:
			currentMove = DeallerMove;
			system("cls");
			break;
		}
	} while (player_answer == PlayerMove);
	
	std::cout << getWhoMove(PlayerMove) << "\'s card is: ";
	player.printCard();
	std::cout << "\n\n" << getWhoMove(currentMove) << "\'s card is: ";
	dealer.printCard();
	
	while (dealer.m_score < 17)
	{
		std::cout << "\n\nDealer take card ";
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		std::cout << ptr_currentCard->GetCard();
		dealer.addCard(ptr_currentCard);
		std::cout << "\nScore is " << dealer.m_score;
	}
	if (dealer.m_score > 21)return true;
	return (21 - player.m_score) <= (21 - dealer.m_score);
}
