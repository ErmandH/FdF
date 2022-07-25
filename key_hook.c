/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharuni < eharuni@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 21:53:31 by eharuni           #+#    #+#             */
/*   Updated: 2022/01/15 21:53:31 by eharuni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_key(int k)
{
	if (k == 126 || k == 125 || k == 123 || k == 124 || k == 6
		|| k == 7 || k == 23 || k == 26 || k == 18 || k == 20 || k == 8
		|| k == 11 || k == 57 || k == 2)
		return (1);
	return (0);
}

void	rainbow_color(t_dot **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y])
	{
		x = 0;
		while (1)
		{
			map[y][x].color = color_decider(y);
			map[y][x].is_rainbow = 1;
			if (map[y][x].is_last)
				break ;
			x++;
		}
		y++;
	}
	map[0][0].is_rainbow = 1;
}

void	two_color(t_dot **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y])
	{
		x = 0;
		while (1)
		{
			if (!map[y][x].z)
				map[y][x].color = 0xfefdfc;
			else
				map[y][x].color = 0xff8eb5;
			map[y][x].is_rainbow = 0;
			if (map[y][x].is_last)
				break ;
			x++;
		}
		y++;
	}
	map[0][0].is_rainbow = 0;
}

static void	treat_key(int key, t_dot *def)
{
	if (key == 126)
		def->y_locate -= 15;
	else if (key == 125)
		def->y_locate += 15;
	else if (key == 123)
		def->x_locate -= 15;
	else if (key == 124)
		def->x_locate += 15;
	else if (key == 6)
		def->zoom += 2;
	else if (key == 7)
		def->zoom -= 2;
	else if (key == 23)
		def->z_scale += 0.5;
	else if (key == 26)
		def->z_scale -= 0.5;
	else if (key == 18)
		def->angle -= 0.15;
	else if (key == 20)
		def->angle += 0.15;
	else if (key == 2)
		set_iso(def);
}

int	key_hook(int key, t_dot **map)
{
	t_dot	*def_dot;
	t_img	*img;

	def_dot = &map[0][0];
	if (is_key(key))
	{
		mlx_destroy_image(def_dot->mlx_ptr, def_dot->img->img);
		free(def_dot->img);
		img = init_img(def_dot);
		def_dot->img = img;
		if (key == 8)
			colorize(map);
		treat_key(key, def_dot);
		draw(map, def_dot, def_dot->img);
	}
	if (key == 53)
	{
		mlx_destroy_image(def_dot->mlx_ptr, def_dot->img->img);
		mlx_destroy_window(def_dot->mlx_ptr, def_dot->win_ptr);
		free(def_dot->img);
		free_map(map);
		exit(0);
	}
	return (0);
}
