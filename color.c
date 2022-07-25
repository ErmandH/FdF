/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharuni < eharuni@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:50:29 by eharuni           #+#    #+#             */
/*   Updated: 2022/01/15 23:50:29 by eharuni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	color_decider(size_t n)
{
	if (n == 0)
		return (0xFF0000);
	else if (n == 1)
		return (0xFF6400);
	else if (n == 2)
		return (0xFFDC00);
	else if (n == 3)
		return (0xC6FF00);
	else if (n == 4)
		return (0x65FF00);
	else if (n == 5)
		return (0x00FF6B);
	else if (n == 6)
		return (0x00FFBC);
	else if (n == 7)
		return (0x00F5FF);
	else if (n == 8)
		return (0x007EFF);
	else if (n == 9)
		return (0x1500FF);
	else if (n == 10)
		return (0x7D00FF);
	else if (n == 11)
		return (0xD900FF);
	return (color_decider(n % 11));
}

void	colorize(t_dot **map)
{
	t_dot	*def_dot;

	def_dot = &map[0][0];
	if (!def_dot->is_rainbow)
		rainbow_color(map);
	else
		two_color(map);
}

void	set_color(t_dot *row, size_t y, size_t x)
{
	size_t	i;

	i = 0;
	while (i < x)
	{
		row[i].color = color_decider(y);
		i++;
	}
}
