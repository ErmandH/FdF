/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharuni <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:01:58 by eharuni           #+#    #+#             */
/*   Updated: 2021/12/11 13:02:00 by eharuni          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	last_index;

	last_index = ft_strlen(s) - 1;
	if (s[last_index + 1] == (char)c)
		return ((char *)(s + ft_strlen(s)));
	while (last_index >= 0 && s[last_index])
	{
		if (s[last_index] == (char)c)
			return ((char *)(s + last_index));
		last_index--;
	}
	return (NULL);
}
