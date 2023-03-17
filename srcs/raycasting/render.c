/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:14:11 by dly               #+#    #+#             */
/*   Updated: 2023/03/09 13:38:42 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	get_rgb(int r, int g, int b)
{
	return (0 << 24 | r << 16 | g << 8 | b);
}

int	background(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			if (y < WIN_HEIGHT / 2)
				my_mlx_pixel_put(&data->img, x, y,
					get_rgb(data->color_ceiling[0],
						data->color_ceiling[1], data->color_ceiling[2]));
			else
				my_mlx_pixel_put(&data->img, x, y,
					get_rgb(data->color_floor[0],
						data->color_floor[1], data->color_floor[2]));
			y++;
		}
		x++;
	}
	return (0);
}
