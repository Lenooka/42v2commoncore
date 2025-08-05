#include "phonebook.hpp"


int	ft_strlen(std::string s)
{
	int i = 0;

	while (s[i])
		i++;
	return i;
}

void	colum_write(std::string s)
{
	int	len;

	len = s.length();
	if (len <= 10)
	{
		std::cout << s;
		int x = 0;
		x = 10 - len;
		while (x != 0)
		{
			std::cout << " ";
			x--;
		}
		std::cout << "  | ";
	}
	else if (len > 10)
	{
		int y = 0;
		while (y < 10)
		{
			std::cout << s[y];
			y++;
		}
		std::cout << ".";
		std::cout << " | ";
	}
}

void search_funct(Phonebook book)
{
	int i = 1;

	if (book.contact_am == 0)
	{
		std::cout << "\x1B[91mNo contacts\n";
		return;
	}
	std::cout << "\n";
	std::cout << "\x1B[92m";
	for (int c = 52; c >= 0; c--)
		std::cout << "_";
	std::cout << "\n";
	while (i <= book.contact_am)
	{
		if (book.contacts[i].empty == 0)
		{
			std::cout << "| " << i << ".      | ";
			colum_write(book.contacts[i].Name);
			colum_write(book.contacts[i].Last);
			colum_write(book.contacts[i].Nick);
			std::cout << "\n";
		}
		i++;
	}
	for (int c = 52; c >= 0; c--)
		std::cout << "‾";
	std::cout << "\n";
	std::string s;
	std::cout << "Insert contact index to see details : ";
	getline(std::cin, s);
	if (s.empty())
		return ;
	std::stringstream ss (s);
	int d = 0;
	ss >> d;
	if (ss.fail() || d <= 0 || d > book.contact_am)
	{
		std::cout << "\x1B[91mWrong input!\n";
		return;
	}
	else
	{
		std::cout << book.contacts[d].Name << "\n";
		std::cout << book.contacts[d].Last << "\n";
		std::cout << book.contacts[d].Nick << "\n";
		std::cout << book.contacts[d].Phone << "\n";
		std::cout << book.contacts[d].Secret << "\n";

	}
}


std::string	add_phone(Phonebook book, std::string mess)
{
	std::string s;
	(void)book;
	std::cout << mess;
	getline(std::cin, s);
	std::stringstream ss (s);
	int d = 0;
	ss >> d;
	if (s.empty())
	{
		std::cout << "\x1B[91mField can't be empty!\n";
		return std::string();

	}
	if (ss.fail() || d <= 0)
	{
		std::cout << "\x1B[91mWrong input!\n";
		return std::string();
	}
	return (s);
}

std::string	add_loop(std::string mess)
{
	std::string s;
	std::cout << mess;
	getline(std::cin, s);
	if (s.empty())
	{
		std::cout << "\x1B[91mField can't be empty!\n";
		return std::string();
	}
	return s;
}

Contact add_funct(int i)
{
	Phonebook book;
	std::string s;
	book.contacts[i].empty = 0;
	book.contacts[i].Name = add_loop("First name : ");
	if (book.contacts[i].Name.empty())
	{
		book.contacts[i].empty = 1;
		return (book.contacts[i]);
	}
	book.contacts[i].Last = add_loop("Last name : ");
	if (book.contacts[i].Last.empty())
	{
		book.contacts[i].empty = 1;
		return (book.contacts[i]);
	}
	book.contacts[i].Nick = add_loop("Nickname : ");
	if (book.contacts[i].Nick.empty())
	{
		book.contacts[i].empty = 1;
		return (book.contacts[i]);
	}
	book.contacts[i].Phone = add_phone(book, "Phone number :");
	if (book.contacts[i].Phone.empty())
	{
		book.contacts[i].empty = 1;
		return (book.contacts[i]);
	}
	book.contacts[i].Secret = add_loop("Darkest secret : ");
	if (book.contacts[i].Secret.empty())
	{
		book.contacts[i].empty = 1;
		return (book.contacts[i]);
	}
	book.contacts[i].indx = i;
	book.contacts[i].empty = 0;
	return (book.contacts[i]);
}

int main()
{
	Phonebook book;
	int i = 1;
	
	book.contact_am = 0;
	book.empty2 = 0;
	while (!std::cin.fail())
	{
		if (i == 9)
			i = 1;
		std::string s;
		std::cout << "\x1B[95m";
		std::cout << "Expected commands : ADD, SEARCH, EXIT : ";
		getline(std::cin, s);
		if (s.empty())
			return (1);
		if (s == "ADD")
		{
			book.contacts[i] =  add_funct(i);
			if (book.contact_am < 8 && book.contacts[i].empty == 0)
				book.contact_am++;
			if (book.contacts[i].empty == 0)
				i++;
		}
		else if (s == "SEARCH")
			search_funct(book);
		else if (s == "EXIT")
			break;
	}
	return 0;
}