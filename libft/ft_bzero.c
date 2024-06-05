/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaladri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:45:38 by gsaladri          #+#    #+#             */
/*   Updated: 2023/10/10 11:45:58 by gsaladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *ptr, size_t x)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)ptr;
	while (i < x)
	{
		p[i] = '\0';
		i++;
	}
	return (ptr);
}

// Apaga a memória (passa a 0), começando no pointer ptr e acabando no size_t 'x' //

/*
int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	size_t arr_size = sizeof(arr);
	char str[] = "Guilherme";
	size_t str_size = strlen(str);

	printf("Original array: ");
	for (size_t i = 0; i < arr_size / sizeof(int); i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	ft_bzero(arr, arr_size);

	printf("After bzero: ");
	for (size_t i = 0; i < arr_size / sizeof(int); i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	printf("Original string: %s\n", str);

	ft_bzero(str, str_size);

	printf("After bzero: %s\n", str);

	return (0);
}
*/