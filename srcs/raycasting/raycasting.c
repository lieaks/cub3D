/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:42:30 by dly               #+#    #+#             */
/*   Updated: 2023/03/10 16:03:15 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	init_raycasting(t_data *data)
{
	data->ray.camerax = 2 * data->ray.x / (double)WIN_WIDTH - 1;
	data->ray.raydirx = data->ray.dirx + data->ray.planex * data->ray.camerax;
	data->ray.raydiry = data->ray.diry + data->ray.planey * data->ray.camerax;
	data->ray.mapx = (int)data->ray.posx;
	data->ray.mapy = (int)data->ray.posy;
	return (0);
}

int	get_delta_dist(t_data *data)
{
	if (data->ray.raydirx == 0)
		data->ray.deltadistx = INT_MAX;
	else
		data->ray.deltadistx = fabs(1 / data->ray.raydirx);
	if (data->ray.raydiry == 0)
		data->ray.deltadisty = INT_MAX;
	else
		data->ray.deltadisty = fabs(1 / data->ray.raydiry);
	return (0);
}

int	perp_wall_dist(t_data *data)
{
	if (data->ray.side == 0)
		data->ray.perpwalldist = (data->ray.sidedistx - data->ray.deltadistx);
	else
		data->ray.perpwalldist = (data->ray.sidedisty - data->ray.deltadisty);
	return (0);
}

int	raycasting(t_data *data)
{
	data->ray.x = 0;
	while (data->ray.x < WIN_WIDTH)
	{
		init_raycasting(data);
		get_delta_dist(data);
		get_step(data);
		dda(data);
		perp_wall_dist(data);
		draw_col(data);
		data->ray.x++;
	}
	return (0);
}
