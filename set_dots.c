/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dots.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharuni < eharuni@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 21:44:39 by eharuni           #+#    #+#             */
/*   Updated: 2022/01/15 21:44:39 by eharuni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_dot *dot, double angle)
{
	float	prev_x;
	float	prev_y;

	prev_x = dot->x;
	prev_y = dot->y;
	dot->x = (prev_x - prev_y) * cos(angle);
	dot->y = (prev_x + prev_y) * sin(angle) - dot->z;
}

void	set_iso(t_dot	*def)
{
	if (def->is_iso)
		def->is_iso = 0;
	else
		def->is_iso = 1;
}

void	set_dots_with_default(t_dot *dot0, t_dot *dot1, t_dot *prm)
{
	dot0->x *= prm->zoom;
	dot0->y *= prm->zoom;
	dot1->x *= prm->zoom;
	dot1->y *= prm->zoom;
	dot0->z *= prm->z_scale;
	dot1->z *= prm->z_scale;
	if (prm->is_iso)
	{
		isometric(dot0, prm->angle);
		isometric(dot1, prm->angle);
	}
	dot0->x += prm->x_locate;
	dot0->y += prm->y_locate;
	dot1->x += prm->x_locate;
	dot1->y += prm->y_locate;
}
