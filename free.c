/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharuni < eharuni@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:11:23 by eharuni           #+#    #+#             */
/*   Updated: 2022/02/08 19:11:23 by eharuni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_columns(char **split)
{
	int		y;

	y = 0;
	while (split[y])
	{
		free(split[y]);
		y++;
	}
}

void	free_map(t_dot	**map)
{
	int		y;

	y = 0;
	while (map[y])
	{
		free(map[y]);
		y++;
	}
	free(map);
}
