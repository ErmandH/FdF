/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:09:52 by marvin            #+#    #+#             */
/*   Updated: 2022/01/15 17:09:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	float	f_abs(float x)
{
	if (x > 0)
		return (x);
	return (-x);
}

static void	my_pixel_put(t_img	*i, t_dot d, t_dot *def, int color)
{
	char	*dst;

	if (d.x >= 0 && d.x < def->win_x && d.y >= 0 && d.y < def->win_y)
	{
		dst = i->addr + ((int)d.y * i->size_line + (int)d.x * (i->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

static int	find_steps(t_dot dot0, t_dot dot1)
{
	int		steps;
	float	delta_x;
	float	delta_y;

	delta_x = dot1.x - dot0.x;
	delta_y = dot1.y - dot0.y;
	if (f_abs(delta_x) > f_abs(delta_y))
		steps = (int)f_abs(delta_x);
	else
		steps = (int)f_abs(delta_y);
	return (steps);
}

static void	line_draw(t_dot d0, t_dot d1, t_dot *prm, t_img *img)
{
	float	x_inc;
	float	y_inc;
	int		steps;
	int		color;

	set_dots_with_default(&d0, &d1, prm);
	steps = find_steps(d0, d1);
	x_inc = (d1.x - d0.x) / (float)steps;
	y_inc = (d1.y - d0.y) / (float)steps;
	color = d0.color;
	while ((int)(d0.x - d1.x) || (int)(d0.y - d1.y))
	{
		my_pixel_put(img, d0, prm, color);
		d0.x += x_inc;
		d0.y += y_inc;
	}
}

void	draw(t_dot **map, t_dot *def_dot, t_img *im)
{
	size_t	row;
	size_t	col;

	row = 0;
	col = 0;
	while (map[row])
	{
		col = 0;
		while (1)
		{
			if (map[row + 1])
				line_draw(map[row][col], map[row + 1][col], def_dot, im);
			if (!map[row][col].is_last)
				line_draw(map[row][col], map[row][col + 1], def_dot, im);
			if (map[row][col].is_last)
				break ;
			col++;
		}
		row++;
	}
	mlx_put_image_to_window(def_dot->mlx_ptr, def_dot->win_ptr, im->img, 0, 0);
}
