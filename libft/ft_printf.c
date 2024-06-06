/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaladri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:26:36 by gsaladri          #+#    #+#             */
/*   Updated: 2023/10/24 12:26:37 by gsaladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		contagem;

	i = 0;
	contagem = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			ft_formatspecifier(str[i], args, &contagem);
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
*/

#include "ft_printf.h"

void	ft_char(char c, int *contagem)
{
	write(1, &c, 1);
	*contagem += 1;
}

static void	ft_hexa_helper(unsigned int n, char uplow, int *contagem)
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
	}
	else
	{
		write(1, &low[n], 1);
		*contagem += 1;
	}
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

static void	ft_pointer_helper_v3(int *contagem)
{
	write(1, "0x", 2);
	*contagem += 2;
}

static void	ft_pointer_helper(unsigned long n, int *contagem)
{
	int		i;
	int		nbr;
	char	*digits;
	char	str[16];

	i = 0;
	nbr = 0;
	digits = "0123456789abcdef";
	while (n > 0)
	{
		nbr = n % 16;
		str[i++] = digits[nbr];
		n /= 16;
	}
	ft_pointer_helper_v3(contagem);
	while (i > 0)
	{
		write(1, &str[--i], 1);
		*contagem += 1;
	}
}

void	ft_pointer(unsigned long nbr, int *contagem)
{
	if (nbr == 0)
	{
		write(1, "(nil)", 5);
		*contagem += 5;
		return ;
	}
	ft_pointer_helper(nbr, contagem);
}

void	ft_unsigned(unsigned int n, int *contagem)
{
	if (n > 4294967295)
		return ;
	if (n >= 10)
	{
		ft_nbr((n / 10), contagem);
	}
	ft_char(n % 10 + '0', contagem);
}

void	ft_nbr(int n, int *contagem)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*contagem += 11;
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
	if (s == NULL)
	{
		write(1, "(null)", 6);
		*contagem += 6;
		return ;
	}
	while (*s)
	{
		ft_char(((char)*s), contagem);
		s++;
	}
}

void	ft_formatspecifier(char specifier, va_list args, int *contagem)

{
	if (specifier == 'd' || specifier == 'i')
		ft_nbr(va_arg(args, int), contagem);
	else if (specifier == 'u')
		ft_unsigned(va_arg(args, unsigned int), contagem);
	else if (specifier == 'c')
		ft_char(va_arg(args, int), contagem);
	else if (specifier == 's')
		ft_str(va_arg(args, char *), contagem);
	else if (specifier == 'p')
		ft_pointer(va_arg(args, unsigned long), contagem);
	else if (specifier == 'x')
		ft_hexa(va_arg(args, int), 'x', contagem);
	else if (specifier == 'X')
		ft_hexa(va_arg(args, int), 'X', contagem);
	else if (specifier == '%')
		ft_char('%', contagem);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		contagem;

	i = 0;
	contagem = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			ft_formatspecifier(str[i], args, &contagem);
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

int	main()
{
	ft_printf("String: %s\n", "Guilherme");
	ft_printf("Integer: %i e %u\n", -2147483648, 2147483647);
	ft_printf("Unsigned: %u\n", 42);
	ft_printf("Pointer: %p\n", 255);
	ft_printf("hexa: %x\n", 255);
	ft_printf("HEXA: %X\n", 255);
	ft_printf("Percent: %%\n");
}
