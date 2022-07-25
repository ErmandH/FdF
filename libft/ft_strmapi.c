/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharuni <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:54:49 by eharuni           #+#    #+#             */
/*   Updated: 2021/12/11 13:00:41 by eharuni          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	int		len;
	int		s_index;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	s_index = 0;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	while (s[s_index])
	{
		ret[s_index] = f(s_index, s[s_index]);
		s_index++;
	}
	ret[s_index] = '\0';
	return (ret);
}
