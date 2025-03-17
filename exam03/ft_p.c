#include <unistd.h>
#include <stdarg.h>

size_t  ft_strlen(char *s)
{
    size_t l = 0;

    while (s[l])
        l++;
    return (l);
}

int ft_putnbr(int n)
{
    int len = 0;

    if (n == -2147483648)
    {
        len += ft_print_s("-2147483648");
        return (len);
    }
    if (n < 0)
    {
        len += write(1, "-", 1);
        n = -n;
    }
    if (n > 9)
    {
        len += ft_putnbr(n / 10);
        len += ft_putnbr(n % 10);
    }
    else
    {
        n = n + '0';
        len += write(1, &n, 1);
    }
    return (len);
}

int ft_print_d(int n)
{
    int len = 0;

    if (n == 0)
    {
        len += ft_putchar('0');
        return (len);
    }
    len += ft_putnbr(n);
    return (n);
}

int ft_putx(unsigned int x)
{
    int len = 0;

    if (x >= 16)
    {
        len += ft_putx(x / 16);
        len += ft_putx(x % 16);
    }
    else
    {
        if (x < 10)
        {
            len += ft_putchar(x + '0');
        }
        else
        {
            len += ft_putchar((x - 10 + 'a'));
        }
    }
    return (len);
}

int ft_print_x(unsigned int x)
{
    int len = 0;

    if (x == 0)
    {
        len += ft_putchar('0');
        return (len);
    }
    len += ft_putx(x);
    return (x);
}

int ft_putchar(int c)
{
    write(1, &c, 1);
    return (1);
}

int ft_print_s(char *s)
{
    int len = 0;
    if (!s)
    {
        len += write(1, "(null)", 6);
        return (len);
    }
    int l = ft_strlen(s);
    len += write(1, s, l);
    return (len);
}

int choosep(va_list *arg, char form)
{
    int len = 0;

    if (form == 's')
        len += ft_print_s(va_arg(*arg, char *));
    else if (form == 'd')
        len += ft_print_d(va_arg(*arg, int));
    else if (form == 'x')
        len += ft_print_x(va_arg(*arg, unsigned int));
    else if (form == '%')
        len += ft_putchar('%');
    return (len);

}


int	ft_printf(const char *str, ...)
{
    va_list arg;
    int len = 0;
    int i = 0;
    va_start(arg, str);
    while(str[i])
    {
        if (str[i] == '%')
        {
            len += choosep(&arg, str[i + 1]);
            i++;
        }
        else
            len += ft_putchar(str[i]);
        i++;
    }
    va_end(arg);
    return (len);
}