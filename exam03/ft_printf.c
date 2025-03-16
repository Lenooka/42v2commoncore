# include <stdarg.h>
# include <unistd.h>





size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	ft_printf_str(char *s)
{
	int	len;
	int	c;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	c = ft_strlen(s);
	len = write(1, s, c);
	return (len);
}

int	ft_printf_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printf_percent(void)
{
	int		len;
	char	c;

	c = '%';
	len = ft_printf_char(c);
	return (len);
}
static int	ft_putnbr(int n, int fd)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		len = write(fd, "-2147483648", 11);
		return (len);
	}
	if (n < 0)
	{
		len += write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		len += ft_putnbr(n / 10, fd);
		len += ft_putnbr(n % 10, fd);
	}
	else
	{
		n = n + '0';
		len += write(fd, &n, fd);
	}
	return (len);
}

int	ft_printf_nbr(int d)
{
	int	len;

	if (d == 0)
	{
		len = write(1, "0", 1);
		return (len);
	}
	len = ft_putnbr(d, 1);
	return (len);
}

static int	ft_hex(unsigned int n, int x)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += ft_hex(n / 16, x);
		len += ft_hex(n % 16, x);
	}
	else
	{
		if (n < 10)
		{
			len += ft_printf_char((n + '0'));
		}
		else
		{
			if (x == 0)
				len += ft_printf_char((n - 10 + 'a'));
			else if (x == 1)
				len += ft_printf_char((n - 10 + 'A'));
		}
	}
	return (len);
}

int	ft_printf_hex(unsigned int n, int x)
{
	int	len;

	if (n == 0)
	{
		len = write(1, "0", 1);
		return (len);
	}
	len = ft_hex(n, x);
	return (len);
}

static	int	ft_printf_pars(va_list *args, const char format)
{
	int	c;

	c = 0;
	if (format == 's')
		c += ft_printf_str(va_arg(*args, char *));
	else if (format == 'd')
		c += ft_printf_nbr(va_arg(*args, int));
	else if (format == 'x')
		c += ft_printf_hex(va_arg(*args, unsigned int), 0);
	else if (format == '%')
		c += ft_printf_percent();
	return (c);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		c;

	i = 0;
	c = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			c += ft_printf_pars(&args, str[i + 1]);
			i++;
		}
		else
			c += ft_printf_char(str[i]);
		i++;
	}
	va_end(args);
	return (c);
}
