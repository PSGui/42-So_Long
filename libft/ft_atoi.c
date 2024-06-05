/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaladri <gsaladri@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:25:15 by gsaladri          #+#    #+#             */
/*   Updated: 2023/10/19 20:25:19 by gsaladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (sign * result);
}

// Transforma uma string de números numa integer //

/*
int	main()
{
	const char str[] = "-123456789";
	const char str2[] = "0";
	const char str3[] = "-2147483648";
	const char str4[] = "abc";

	printf("Expected: -123456789  | Got: %d\n", ft_atoi(str));
	printf("Expected: 0 	      | Got: %d\n", ft_atoi(str2));
	printf("Expected: -2147483648 | Got: %d\n", ft_atoi(str3));
	printf("Expected: 0  	      | Got: %d\n", ft_atoi(str4));
	return (0);
}
*/