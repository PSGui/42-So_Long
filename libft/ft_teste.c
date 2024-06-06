#include "ft_printf.h"

void	ft_char(char c, int *contagem)
{
	write(1, &c, 1);
        *contagem += 1;
}

static void     ft_hexa_helper(unsigned int n, char uplow, int *contagem)
{
	char	*low;
	char	*upp;

	low = "0123456789abcdef";
	upp = "0123456789ABCDEF";
	if (n >= 16)
	{
		ft_hexa_helper(n / 16, uplow, contagem);
		n = n % 16;
	}
	if (uplow == 'X')
	{
		write(1, &upp[n], 1);
		*contagem += 1;
		return ;
	}
	write(1, &low[n], 1);
	*contagem += 1;
}

void	ft_hexa(unsigned int nbr, char uplow, int *contagem)
{
	if (nbr == 0)
	{
		write(1, "0", 1);
		*contagem += 1;
		return ;
	}
        ft_hexa_helper(nbr, uplow, contagem);
}

void	ft_nbr(int n, int *contagem)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = -n;
			*contagem += 1;
		}
		if (n >= 10)
		{
			ft_nbr((n / 10), contagem);
		}
		ft_char(n % 10 + '0', contagem);
	}
}

void	ft_str(char *s, int *contagem)
{
	int	i;

	i = 0;
	if (s != 0)
	{
		while(s[i] != '\0')
		{
			write(1, &s[i], 1);
			i++;
			*contagem += 1;
		}
	}
	else
		*contagem += write(1, "(null)", 6);
}

void    ft_formatspecifier(char specifier, va_list args, int *contagem)
{
        if (specifier == 'd' || specifier == 'i')
                ft_nbr(va_arg(args, int), contagem);
        else if (specifier == 'u')
                ft_nbr(va_arg(args, unsigned int), contagem);
        else if (specifier == 'c')
                ft_char(va_arg(args, int), contagem);
        else if (specifier == 's')
                ft_str(va_arg(args, char *), contagem);
        else if (specifier == 'p')
                ft_str(va_arg(args, void *), contagem);
        else if (specifier == 'x')
                ft_hexa(va_arg(args, int), 'x', contagem);
	else if (specifier == 'X')
                ft_hexa(va_arg(args, int), 'X', contagem);
        else if (specifier == '%')
                ft_char('%', contagem);
}

int     ft_printf(const char *str, ...)
{
        int     i;
        va_list args;
        int     contagem;

        i = 0;
        va_start(args, str);
        while (str[i] != '\0')
        {
                if (str[i] == '%')
		{
			ft_formatspecifier(str[i + 1], args, &contagem);
			i++;
		}
                else
                {
                        write(1, &str[i], 1);
                        contagem += 1;
                }
                i++;
        }
        va_end(args);
        return (contagem);
}

int     main()
{
        ft_printf("Integer: %i\n", -42);
	ft_printf("Integer with 'u': %u\n", -420);
	ft_printf("Unsigned: %u\n", 42);
	ft_printf("Char: %c\n", 'C');
	ft_printf("String: %s\n", "Guilherme");
	ft_printf("hexa: %x\n", 255);
	ft_printf("HEXA: %X\n", 255);
        return (0);
}