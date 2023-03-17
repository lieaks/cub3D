/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:45:45 by dly               #+#    #+#             */
/*   Updated: 2023/03/10 11:46:55 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	draw_block_at(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < MINIMAP_PPC)
	{
		j = 0;
		while (j < MINIMAP_PPC)
		{
			my_mlx_pixel_put(&data->img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_block(t_data *data, int i, int j)
{
	static int	x = 10;
	static int	y = 10;

	if (i < 0 || j < 0 || i >= data->map_height || j >= data->map_width)
	{
	}
	else if (j == (int)data->ray.posx && i == (int)data->ray.posy)
		draw_block_at(data, x, y, MINIMAP_PLAYER_COLOR);
	else if (data->map[i][j] == '1')
		draw_block_at(data, x, y, MINIMAP_WALL_COLOR);
	else if (data->map[i][j] == '0')
		draw_block_at(data, x, y, MINIMAP_FLOOR_COLOR);
	x += MINIMAP_PPC;
	if (x > MINIMAP_SIZE * MINIMAP_PPC)
	{
		x = 10;
		y += MINIMAP_PPC;
	}
	if (y > MINIMAP_SIZE * MINIMAP_PPC)
	{
		x = 10;
		y = 10;
	}
}

int	minimap(t_data *data)
{
	int	x;
	int	y;

	if (data->map_height > WIN_HEIGHT * MINIMAP_SIZE
		|| data->map_width > WIN_WIDTH * MINIMAP_SIZE)
		return (1);
	y = (int)data->ray.posy - (MINIMAP_SIZE / 2);
	if (MINIMAP_SIZE % 2 != 0)
		y--;
	while (y < (int)data->ray.posy + (MINIMAP_SIZE / 2))
	{
		x = (int)data->ray.posx - (MINIMAP_SIZE / 2);
		if (MINIMAP_SIZE % 2 != 0)
			x--;
		while (x < (int)data->ray.posx + (MINIMAP_SIZE / 2))
		{
			draw_block(data, y, x);
			x++;
		}
		y++;
	}
	return (0);
}
