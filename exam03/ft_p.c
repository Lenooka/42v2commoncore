#include <unistd.h>
#include <stdarg.h>

size_t ft_strlen(char *s)
{
    size_t i = 0;
    while (s[i])
        i++;
    return i;
}

int ft_putchar(int c)
{
    int len = write(1, &c, 1);
    return (len);
}
int ft_printf_str(char *s)
{
    int len = 0;
    int i = 0;
    if (!s)
    {
        len = write(1, "(null)", 1);
        return (len);
    }
    i = ft_strlen(s);
    len = write(1, s, i);
    return (i);
}

int ft_putnbr(int n)
{
    int len = 0;
    char c;
    if (n == -2147483648)
    {
        len = ft_printf_str("-2147483648");
        return (len);
    }
    if (n < 0)
    {
        len += write(1, '-', 1);
        n = -n;
    }
    if (n > 10)
    {
        len += ft_putnbr(n / 10);
        len += ft_putnbr(n % 10);
    }
    else
    {
        c = n + '0';
        len += write(1, &c, 1);
    }
    return (len);
}
int ft_printf_nbr(int n)
{
    int len = 0;
    if (n == 0)
    {
        len = ft_putchar('0');
        return (len);
    }
    len = ft_putnbr(n);
    return (len);
}
int ft_putx(unsigned int x)
{
    int len = 0;
    if (x >= 16)
    {
        len += ft_putx(x / 16);
        len += ft_putx(x % 16);
    }
    if (x <= 9)
        len += ft_putchar((x + '0'));
    else
        len += ft_putchar((x - 10 + 'a'));
    return (len);
}

int ft_printf_hex(unsigned int x)
{
    int len = 0;
    if (x == 0)
    {
        len = ft_putchar('0');
        return (len);
    }
    len = ft_putx(x);
    return (len);
}

int choose_format(va_list *args, const char format)
{
        int	c;
    
        c = 0;
        if (format == 's')
            c += ft_printf_str(va_arg(*args, char *));
        else if (format == 'd')
            c += ft_printf_nbr(va_arg(*args, int));
        else if (format == 'x')
            c += ft_printf_hex(va_arg(*args, unsigned int));
        // else if (format == '%')
        //     c += ft_printf_percent();
        return (c);
}

int	ft_printf(const char *str, ...)
{
    va_list arg;
    int i = 0;
    int ret = 0;

    va_start(arg, str);
    while (str[i])
    {
        if (str[i] == '%')
        {
            ret = choose_format(&arg, str[i + 1]);
            i++;
        }
        else
            ret += ft_putchar(str[i]);
        i++;
    }
    va_end(arg);
    return (ret);
}