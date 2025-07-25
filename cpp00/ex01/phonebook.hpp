#include <iostream>

class Contact {

	public:
	Contact(){}
	~Contact(){}
	std::string Name;
	int	indx;
	std::string Nick;
	std::string Last;
	std::string Phone;
	std::string Secret;

};

class Phonebook {

	public:
	Phonebook(){}
	~Phonebook(){}
	int	amm;
	Contact contacts[8];
};