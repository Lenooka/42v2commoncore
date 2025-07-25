#include "phonebook.hpp"

void	search_funct(Phonebook book)
{
	int	i = 1;

	while (i < book.amm)
	{
		std::cout << book.contacts[i].Name << "\n";
		i++;
	}
}

Contact	add_funct(int i)
{
	Phonebook book;
	std::string s;
	std::cout << "\nFirst name : ";
	getline(std::cin, s);
	book.contacts[i].Name = s;
	std::cout << book.contacts[i].Name << "\n";
	std::cout << "Last name : ";
	getline(std::cin, s);
	std::cout << book.contacts[i].Last << "\n";
	std::cout << "Nickname : ";
	getline(std::cin, s);
	std::cout << book.contacts[i].Nick << "\n";
	std::cout << "Phone number : ";
	getline(std::cin, s);
	std::cout << book.contacts[i].Phone << "\n";
	std::cout << "Darkest secret : ";
	getline(std::cin, s);
	std::cout << book.contacts[i].Secret << "\n";
	book.contacts[i].indx = i;
	return (book.contacts[i]);
}

int	main()
{
	Phonebook book;
	int	i = 1;

	while (std::cin)
	{
		if (i == 8)
			i = 1;
		std::string s;
		std::cout << "Expected commands : ADD, SEARCH, EXIT : ";
		getline(std::cin, s);
		if (s == "ADD")
		{
			book.contacts[i] = add_funct(i);
			i++;
			book.amm = 8;
		}
		else if (s == "SEARCH")
			search_funct(book);
		else if (s == "EXIT")
			break ;
	}
	return 1;
}