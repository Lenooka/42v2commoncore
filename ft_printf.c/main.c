#include "ft_printf.h"

int	main()
{
	char c = 'c';
	char	s[7] = "Hello";
	char	*n = NULL;
	int		i = 10;
	int		d = -123;
	int		xe = -1;
	int		x = 220;
	unsigned int  u = 100;
	unsigned int	un = -1;
	void	*mem = "hello";
	void	*nil = NULL;

	ft_printf("My printf %c\n", c);
	printf("printf %c\n", c);
	ft_printf("My printf %s\n", s);
	printf("printf %s\n", s);
	ft_printf("My printf %s\n", n);
	printf("printf %s\n", n);
	ft_printf("My printf %i\n", i);
	printf("printf %i\n", i);
	ft_printf("My printf %d\n", d);
	printf("printf %d\n", d);
	ft_printf("My printf %x\n", xe);
	printf("printf %x\n", xe);
	ft_printf("My printf %X\n", x);
	printf("printf %X\n", x);
	ft_printf("My printf %u\n", u);
	printf("printf %u\n", u);
	ft_printf("My printf %u\n", un);
	printf("printf %u\n", un);
	ft_printf("My printf %p\n", mem);
	printf("printf %p\n", mem);
	ft_printf("My printf %p\n", nil);
	printf("printf %p\n", nil);
	return (0);







}