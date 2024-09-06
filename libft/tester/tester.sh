#!/bin/bash

# Create a directory for the executables if it doesn't exist
mkdir -p exec

# Compile libft (navigate to parent directory and run make)
echo -e "\033[0;33mCompiling libft...\033[0m\n"
cd ..
make re > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo -e "\033[0;31mFailed to compile libft. Exiting.\033[0m"
    exit 1
fi
cd tester

cc -Wall -Wextra -Werror -I.. -o exec/test_isalpha test_isalpha.c -L.. -lft
if [ $? -ne 0 ]; then
    echo -e "\033[0;31mFailed to compile test_isalpha. Exiting.\033[0m"
    exit 1
fi

./exec/test_isalpha
if [ $? -ne 0 ]; then
    echo -e "\033[0;31mTest execution failed.\033[0m"
    exit 1
fi

cc -Wall -Wextra -Werror -I.. -o exec/test_isdigit test_isdigit.c -L.. -lft
if [ $? -ne 0 ]; then
    echo -e "\033[0;31mFailed to compile test_isdigit. Exiting.\033[0m"
    exit 1
fi

./exec/test_isdigit
if [ $? -ne 0 ]; then
    echo -e "\033[0;31mTest execution failed.\033[0m"
    exit 1
fi

cc -Wall -Wextra -Werror -I.. -o exec/test_isascii test_isascii.c -L.. -lft
if [ $? -ne 0 ]; then
    echo -e "\033[0;31mFailed to compile test_isascii. Exiting.\033[0m"
    exit 1
fi

cc -Wall -Wextra -Werror -I.. -o exec/test_isalum test_isalum.c -L.. -lft
if [ $? -ne 0 ]; then
    echo -e "\033[0;31mFailed to compile test_isalum. Exiting.\033[0m"
    exit 1
fi

./exec/test_isalum
if [ $? -ne 0 ]; then
    echo -e "\033[0;31mTest execution failed.\033[0m"
    exit 1
fi

./exec/test_isascii
if [ $? -ne 0 ]; then
    echo -e "\033[0;31mTest execution failed.\033[0m"
    exit 1
fi

cc -Wall -Wextra -Werror -I.. -o exec/test_isprint test_isprint.c -L.. -lft
if [ $? -ne 0 ]; then
    echo -e "\033[0;31mFailed to compile test_isprint. Exiting.\033[0m"
    exit 1
fi

./exec/test_isprint
if [ $? -ne 0 ]; then
    echo -e "\033[0;31mTest execution failed.\033[0m"
    exit 1
fi

cc -Wall -Wextra -Werror -I.. -o exec/test_strlen test_strlen.c -L.. -lft
if [ $? -ne 0 ]; then
    echo -e "\033[0;31mFailed to compile test_strlen.c Exiting.\033[0m"
    exit 1
fi

./exec/test_strlen
if [ $? -ne 0 ]; then
    echo -e "\033[0;31mTest execution failed.\033[0m"
    exit 1
fi

cc -Wall -Wextra -Werror -I.. -o exec/test_memset test_memset.c -L.. -lft
if [ $? -ne 0 ]; then
    echo -e "\033[0;31mFailed to compile test_memset. Exiting.\033[0m"
    exit 1
fi

./exec/test_memset
if [ $? -ne 0 ]; then
    echo -e "\033[0;31mTest execution failed.\033[0m"
    exit 1
fi

cc -Wall -Wextra -Werror -I.. -o exec/test_bzero test_bzero.c -L.. -lft
if [ $? -ne 0 ]; then
    echo -e "\033[0;31mFailed to compile test_bzero. Exiting.\033[0m"
    exit 1
fi

./exec/test_bzero
if [ $? -ne 0 ]; then
    echo -e "\033[0;31mTest execution failed.\033[0m"
    exit 1
fi

cc -Wall -Wextra -Werror -I.. -o exec/test_memcpy test_memcpy.c -L.. -lft
if [ $? -ne 0 ]; then
    echo -e "\033[0;31mFailed to compile test_memcpy. Exiting.\033[0m"
    exit 1
fi

./exec/test_memcpy
if [ $? -ne 0 ]; then
    echo -e "\033[0;31mTest execution failed.\033[0m"
    exit 1
fi

cc -Wall -Wextra -Werror -I.. -o exec/test_memmove test_memove.c -L.. -lft
if [ $? -ne 0 ]; then
    echo -e "\033[0;31mFailed to compile test_memmove. Exiting.\033[0m"
    exit 1
fi

./exec/test_memmove
if [ $? -ne 0 ]; then
    echo -e "\033[0;31mTest execution failed.\033[0m"
    exit 1
fi

cc -Wall -Wextra -Werror -I.. -o exec/test_strlcpy test_strlcpy.c -L.. -lft
if [ $? -ne 0 ]; then
    echo -e "\033[0;31mFailed to compile test_strlcpy. Exiting.\033[0m"
    exit 1
fi

./exec/test_strlcpy
if [ $? -ne 0 ]; then
    echo -e "\033[0;31mTest execution failed.\033[0m"
    exit 1
fi


# Clean the libft files (not executables)
echo -e "\n"
echo -e "\033[0;33mCleaning up...\033[0m"
cd ..
make fclean > /dev/null 2>&1
cd tester
