/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharuni < eharuni@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 11:47:58 by eharuni           #+#    #+#             */
/*   Updated: 2022/02/08 19:17:47 by eharuni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static void	set_default(t_dot *dot)
{
	dot->mlx_ptr = mlx_init();
	dot->win_x = 2000;
	dot->win_y = 1200;
	dot->win_ptr = mlx_new_window(dot->mlx_ptr, dot->win_x, dot->win_y, "fdf");
	dot->x_locate = dot->win_x / 2;
	dot->y_locate = dot->win_y / 4;
	dot->zoom = 20;
	dot->angle = 0.5236;
	dot->z_scale = 1;
	dot->is_iso = 1;
}

t_img	*init_img(t_dot *d)
{
	t_img	*im;

	im = (t_img *)malloc(sizeof(t_img));
	if (!im)
		return (NULL);
	im->img = mlx_new_image(d->mlx_ptr, d->win_x, d->win_y);
	im->addr = mlx_get_data_addr(im->img, &im->bpp, &im->size_line, &im->endi);
	return (im);
}

int	quit(t_dot **map)
{
	(void)map;
	exit(EXIT_SUCCESS);
	return (0);
}

int	main(int ac, char **av)
{
	t_dot	**map;	
	t_dot	*def_dot;
	t_img	*img;

	if (ac != 2)
		error("Arguement count is not 2\n");
	map = read_map(av[1]);
	if (!map)
		error("Error occured in map\n");
	def_dot = &map[0][0];
	set_default(def_dot);
	img = init_img(def_dot);
	def_dot->img = img;
	if (!img)
		return (0);
	draw(map, def_dot, img);
	mlx_hook(def_dot->win_ptr, 17, 1 << 17, &quit, map);
	if (mlx_key_hook(def_dot->win_ptr, key_hook, map) == -1)
		return (0);
	mlx_loop(def_dot->mlx_ptr);
	return (0);
}
