/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharuni <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:33:21 by eharuni           #+#    #+#             */
/*   Updated: 2021/12/11 12:40:51 by eharuni          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_len(int n)
{
	size_t	step;

	if (n == -2147483648)
	{
		n = 147483648;
		step = 2;
	}
	if (n == 0)
		return (1);
	if (n < 0)
	{
		step = 1;
		n = n * -1;
	}
	else if (n != 147483648)
		step = 0;
	while (n)
	{
		step++;
		n /= 10;
	}
	return (step);
}

void	ft_neg_check(char *str, int *n, size_t *index)
{
	if (*n == -2147483648)
	{
		*n = 147483648;
		str[0] = '-';
		str[1] = '2';
		*index = 2;
	}
	if (*n < 0)
	{
		str[0] = '-';
		*index = 1;
		*n = *n * -1;
	}
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	len;
	size_t	i;

	if (n == 0)
		return (ft_strdup("0"));
	len = ft_count_len(n);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	ft_neg_check(res, &n, &i);
	res[len] = '\0';
	while (n && len-- >= i)
	{
		res[len] = n % 10 + 48;
		n /= 10;
	}
	return (res);
}
