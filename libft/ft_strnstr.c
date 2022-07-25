/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharuni <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:55:18 by eharuni           #+#    #+#             */
/*   Updated: 2021/12/11 13:01:49 by eharuni          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	if (!find[0])
		return ((char *)str);
	while (str[i] && i < len)
	{
		while (str[i + c] == find[c] && i + c < len && find[c])
			c++;
		if (!find[c])
			return ((char *)str + i);
		c = 0;
		i++;
	}
	return (NULL);
}
