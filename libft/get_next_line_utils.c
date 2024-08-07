/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaladri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:52:41 by gsaladri          #+#    #+#             */
/*   Updated: 2023/11/21 15:52:42 by gsaladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int r)
{
	int		i;
	char	*p;

	p = (char *)str;
	i = 0;
	while ((unsigned char)str[i] != (unsigned char)r)
	{
		if (!str[i])
			return (0);
		i++;
		p++;
	}
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*mem;

	len1 = 0;
	len2 = 0;
	i = 0;
	if (!s1 && !s2)
		return (0);
	if (s1)
		while (s1[len1])
			len1++;
	if (s2)
		while (s2[len2])
			len2++;
	mem = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!mem)
		return (0);
	if (s1)
		while (*s1)
			mem[i++] = *s1++;
	if (s2)
		while (*s2)
			mem[i++] = *s2++;
	mem[i] = '\0';
	return (mem);
}
