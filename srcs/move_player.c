/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:41:26 by mirsella          #+#    #+#             */
/*   Updated: 2023/03/10 10:27:38 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	move_front(t_data *data)
{
	if (data->map[(int)(data->ray.posy + data->ray.diry
			* data->move.move_speed)][(int)data->ray.posx] == '0')
		data->ray.posy += data->ray.diry * data->move.move_speed;
	if (data->map[(int)data->ray.posy][(int)(data->ray.posx + data->ray.dirx
		* data->move.move_speed)] == '0')
		data->ray.posx += data->ray.dirx * data->move.move_speed;
	return (0);
}

int	move_back(t_data *data)
{
	if (data->map[(int)(data->ray.posy - data->ray.diry
			* data->move.move_speed)][(int)data->ray.posx] == '0')
		data->ray.posy -= data->ray.diry * data->move.move_speed;
	if (data->map[(int)data->ray.posy][(int)(data->ray.posx - data->ray.dirx
		* data->move.move_speed)] == '0')
		data->ray.posx -= data->ray.dirx * data->move.move_speed;
	return (0);
}

int	move_left(t_data *data)
{
	if (data->map[(int)(data->ray.posy - data->ray.planey
			* data->move.move_speed)][(int)data->ray.posx] == '0')
		data->ray.posy -= data->ray.planey * data->move.move_speed;
	if (data->map[(int)data->ray.posy][(int)(data->ray.posx - data->ray.planex
		* data->move.move_speed)] == '0')
		data->ray.posx -= data->ray.planex * data->move.move_speed;
	return (0);
}

int	move_right(t_data *data)
{
	if (data->map[(int)(data->ray.posy + data->ray.planey
			* data->move.move_speed)][(int)data->ray.posx] == '0')
		data->ray.posy += data->ray.planey * data->move.move_speed;
	if (data->map[(int)data->ray.posy][(int)(data->ray.posx + data->ray.planex
		* data->move.move_speed)] == '0')
		data->ray.posx += data->ray.planex * data->move.move_speed;
	return (0);
}

int	update_player_position_and_direction(t_data *data)
{
	if (data->move.front)
		move_front(data);
	if (data->move.back)
		move_back(data);
	if (data->move.left)
		move_left(data);
	if (data->move.right)
		move_right(data);
	if (data->move.rot_left)
		rotate_left(data);
	if (data->move.rot_right)
		rotate_right(data);
	if (data->move.mouse)
	{
		data->move.rot_left = 0;
		data->move.rot_right = 0;
		data->move.mouse = 0;
	}
	data->move.rot_speed = ROT_SPEED;
	data->move.move_speed = MOVE_SPEED;
	return (0);
}
