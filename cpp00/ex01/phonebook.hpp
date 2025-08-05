#include <iostream>
#include <string.h>
#include <sstream> 
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
	int	empty;

};

class Phonebook {

	public:
	Phonebook(){}
	~Phonebook(){}
	int	amm;
	Contact contacts[9];
	int	contact_am;
	int	empty2;
};