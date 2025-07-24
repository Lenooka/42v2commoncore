#include <iostream>

int	main(int argc, char **argv)
{
	if (argc <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n" ;	
	else
	{
		for (int i = 1; i < argc; ++i)
		{
			std::string str = argv[i];
			char c = str[i];
    	   	if (isascii(c) == 0)
			{
				std::cout << "Non ascii characters is not allowed!" << '\n';
				return 1;
			}
		}
		for (int i = 1; i < argc; ++i)
		{
			std::string str = argv[i];
			for (int a = 0; argv[i][a]; ++a)
			{
    	   		str[a] = std::toupper(static_cast<unsigned char>(str[a]));
   		 	}
			std::cout << str;
			if (i == argc - 1)
				std::cout << "\n";
		}
	}
	return (0);
}
