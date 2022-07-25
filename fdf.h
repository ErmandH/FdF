/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharuni < eharuni@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 21:59:15 by eharuni           #+#    #+#             */
/*   Updated: 2022/02/08 19:38:44 by eharuni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx_macos/mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_img
{
	void	*img;

	char	*addr;
	int		bpp;
	int		size_line;
	int		endi;
}	t_img;

typedef struct s_dot
{
	void	*mlx_ptr;
	void	*win_ptr;

	float	x;
	float	y;
	float	z;

	double	angle;
	int		x_locate;
	int		y_locate;
	int		zoom;
	float	z_scale;
	int		is_last;
	int		win_x;
	int		win_y;
	int		color;
	int		is_rainbow;
	int		is_iso;
	t_img	*img;
}	t_dot;

char	*get_next_line(int fd);
t_dot	**read_map(char *map_name);
char	*ft_strjoin_new(char *s1, char *s2);
void	set_dots_with_default(t_dot *dot0, t_dot *dot1, t_dot *prm);
void	draw(t_dot **map, t_dot *default_dot, t_img *img);
void	draw_menu(t_dot def_dot);
int		key_hook(int key, t_dot **map);
void	set_color(t_dot *row, size_t y, size_t x);
t_img	*init_img(t_dot	*def_dot);
int		color_decider(size_t n);
void	isometric(t_dot *dot, double angle);
void	free_columns(char **split);
void	free_map(t_dot	**map);
void	error(char *msg);
void	colorize(t_dot **map);
void	rainbow_color(t_dot **map);
void	two_color(t_dot **map);
void	set_iso(t_dot	*def);

#endif