/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharuni <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:39:38 by eharuni           #+#    #+#             */
/*   Updated: 2021/12/16 17:40:13 by eharuni          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*ft_strdup_new(char *str)
{
	size_t	len;
	size_t	i;
	char	*dup;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin_new(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*res;

	if (!s1)
		s1 = ft_strdup_new("");
	if (!s2 || !s1)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!res)
	{
		free(s1);
		return (NULL);
	}	
	ft_strlcpy(res, s1, s1_len + 1);
	ft_strlcat(res, s2, s1_len + s2_len + 1);
	free(s1);
	return (res);
}
