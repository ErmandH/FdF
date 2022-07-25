/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharuni <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:41:05 by eharuni           #+#    #+#             */
/*   Updated: 2021/12/11 12:41:06 by eharuni          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*start;

	start = *lst;
	if (!start)
		*lst = new;
	while (start)
	{
		if (start->next == NULL)
		{
			start->next = new;
			return ;
		}
		start = start->next;
	}
}
