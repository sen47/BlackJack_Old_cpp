#pragma once
#include<iostream>

template<typename T>
class Check
{
public:
	static T checkInput(const char* out);
};

template<typename T>
inline T Check<T>::checkInput(const char* out)
{
	T in;
	std::cout << '\n' << out;
	std::cout << "\nEnter: ";
	std::cin >> in;
	std::cin.ignore(32767, '\n');
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		system("cls");
		std::cerr << "\nUnvaliable input, try again!";
	}
	return in;
}
