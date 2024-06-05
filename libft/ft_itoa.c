/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaladri <gsaladri@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:26:07 by gsaladri          #+#    #+#             */
/*   Updated: 2023/10/19 20:26:08 by gsaladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nlenght(int n)
{
	size_t	i;

	i = 0;
	if (n == -2146473648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_coloca_numeros(char *ptr, int n, int i)
{
	int	j;

	j = i;
	if (n < 0)
	{
		n = n * -1;
		ptr[0] = '-';
	}
	while (n > 0)
	{
		ptr[i] = n % 10 + 48;
		n = n / 10;
		i--;
	}
	ptr[j + 1] = '\0';
}

char	*ft_itoa(int n)
{
	int		n_len;
	char	*str;
	char	*min;
	char	*nulo;

	min = "-2147483648";
	nulo = "0";
	n_len = ft_nlenght(n);
	if (n == -2147483648 || n == 0)
	{
		if (n == -2147483648)
			str = ft_strdup(min);
		else
			str = ft_strdup(nulo);
		return (str);
	}
	str = malloc(n_len + 1);
	if (!str)
		return (0);
	ft_coloca_numeros(str, n, n_len - 1);
	return (str);
}

// Parecido com atoi mas ao contrário - Passa uma integer para string //

/*
int	main()
{
	int	n = 2147483647;
	int	n1 = -2147483648;
	int	n2 = 0;
	int	n3 = -42;

	printf("Expected: 2147483647  | Got: %s\n", ft_itoa(n));
	printf("Expected: -2147483648 | Got: %s\n", ft_itoa(n1));
	printf("Expected: 0	      | Got: %s\n", ft_itoa(n2));
	printf("Expected: -42 	      | Got: %s\n", ft_itoa(n3));
	return (0);
}
*/