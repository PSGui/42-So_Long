/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaladri <gsaladri@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:25:28 by gsaladri          #+#    #+#             */
/*   Updated: 2023/10/19 20:25:29 by gsaladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*mem;

	mem = malloc(nmemb * size);
	if (!mem)
		return (0);
	ft_bzero(mem, nmemb * size);
	if (!mem)
		return (0);
	return (mem);
}

// Alocação de memória para um size_t 'nmemb' utilizando malloc e //
// 	      depois passar a 0 a memória até size_t		  //

/*
int 	main()
{
	size_t	nmemb = 20;
	size_t	size = 4;
	
	printf("Memória: %p", ft_calloc(nmemb, size));
	return (0);
}
*/