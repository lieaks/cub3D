/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:12:05 by dly               #+#    #+#             */
/*   Updated: 2023/03/10 10:20:38 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}	t_img;

typedef struct s_ray
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	raydirx;
	double	raydiry;
	double	camerax;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	double	perpwalldist;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		x;
	double	wallx;
	double	step;
	double	texpos;
	int		texx;
	int		texy;
}	t_ray;

typedef struct s_move
{
	int		front;
	int		back;
	int		left;
	int		right;
	int		rot_left;
	int		rot_right;
	int		mouse;
	float	rot_speed;
	float	move_speed;
}	t_move;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		**map;
	int			map_width;
	int			map_height;
	t_ray		ray;
	t_move		move;
	t_img		img;
	t_img		no;
	t_img		so;
	t_img		ea;
	t_img		we;
	t_img		item;
	int			color_floor[3];
	int			color_ceiling[3];
}	t_data;

#endif
