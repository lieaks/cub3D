/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 00:15:21 by mirsella          #+#    #+#             */
/*   Updated: 2023/03/09 15:42:38 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	rotate_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->ray.dirx;
	old_plane_x = data->ray.planex;
	data->ray.dirx = data->ray.dirx * cos(-data->move.rot_speed)
		- data->ray.diry * sin(-data->move.rot_speed);
	data->ray.diry = old_dir_x * sin(-data->move.rot_speed)
		+ data->ray.diry * cos(-data->move.rot_speed);
	data->ray.planex = data->ray.planex * cos(-data->move.rot_speed)
		- data->ray.planey * sin(-data->move.rot_speed);
	data->ray.planey = old_plane_x * sin(-data->move.rot_speed)
		+ data->ray.planey * cos(-data->move.rot_speed);
	return (0);
}

int	rotate_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->ray.dirx;
	old_plane_x = data->ray.planex;
	data->ray.dirx = data->ray.dirx * cos(data->move.rot_speed)
		- data->ray.diry * sin(data->move.rot_speed);
	data->ray.diry = old_dir_x * sin(data->move.rot_speed)
		+ data->ray.diry * cos(data->move.rot_speed);
	data->ray.planex = data->ray.planex * cos(data->move.rot_speed)
		- data->ray.planey * sin(data->move.rot_speed);
	data->ray.planey = old_plane_x * sin(data->move.rot_speed)
		+ data->ray.planey * cos(data->move.rot_speed);
	return (0);
}
