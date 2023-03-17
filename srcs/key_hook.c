/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 11:14:04 by mirsella          #+#    #+#             */
/*   Updated: 2023/03/13 12:03:26 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	key_down_handler(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		end_game(data);
	if (keycode == XK_w)
		data->move.front = 1;
	if (keycode == XK_a)
		data->move.left = 1;
	if (keycode == XK_s)
		data->move.back = 1;
	if (keycode == XK_d)
		data->move.right = 1;
	if (keycode == XK_Left)
		data->move.rot_left = 1;
	if (keycode == XK_Right)
		data->move.rot_right = 1;
	return (0);
}

int	key_up_handler(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		end_game(data);
	if (keycode == XK_w)
		data->move.front = 0;
	if (keycode == XK_a)
		data->move.left = 0;
	if (keycode == XK_s)
		data->move.back = 0;
	if (keycode == XK_d)
		data->move.right = 0;
	if (keycode == XK_Left)
		data->move.rot_left = 0;
	if (keycode == XK_Right)
		data->move.rot_right = 0;
	return (0);
}

int	mouse_move_handler(int x, int y, t_data *data)
{
	static int	last_x = 0;

	(void)y;
	if (x <= 5 || x >= WIN_WIDTH - 5)
		mlx_mouse_move(data->mlx, data->win, WIN_WIDTH / 2, y);
	if (x > last_x && !data->move.rot_left)
		data->move.rot_right = 1;
	else if (x < last_x && !data->move.rot_right)
		data->move.rot_left = 1;
	data->move.mouse = 1;
	data->move.rot_speed = ft_abs(x - last_x) * MOUSE_SPEED;
	last_x = x;
	return (0);
}
