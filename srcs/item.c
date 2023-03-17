/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:41:49 by mirsella          #+#    #+#             */
/*   Updated: 2023/03/10 10:24:42 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	load_item(t_data *data)
{
	data->item.img = mlx_xpm_file_to_image(data->mlx, ITEM_PATH,
			&data->item.width, &data->item.height);
	if (!data->item.img)
		return (free_data(data), perror("mlx_xpm_file_to_image"), 1);
	return (0);
}

static void	put_pixels(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < ITEM_SIZE_FACTOR)
	{
		j = 0;
		while (j < ITEM_SIZE_FACTOR)
		{
			if (x + i <= WIN_WIDTH && y + j <= WIN_HEIGHT && x + i >= 0
				&& y + j >= 0)
			{
				my_mlx_pixel_put(&data->img, x + i, y + j, color);
			}
			j++;
		}
		i++;
	}
}

static void	draw_item_to_img(t_data *data, int imgx, int imgy)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < data->item.height)
	{
		x = 0;
		while (x < data->item.width)
		{
			color = get_color_pixel(data->item.img, x, y);
			if (color != PURPLE)
				put_pixels(data, imgx + x * ITEM_SIZE_FACTOR,
					imgy + y * ITEM_SIZE_FACTOR, color);
			x++;
		}
		y++;
	}
}

static void	get_circle_coord_ccw(double index, double radius,
	double *x, double *y)
{
	double	angle;

	angle = 2.0 * M_PI * (1 - (double)index / ITEM_ANIM_DELAY);
	*x = radius * cos(angle);
	*y = radius * sin(angle);
}

int	draw_item(t_data *data)
{
	static int	i = 0;
	double		x;
	double		y;

	get_circle_coord_ccw(i, 70, &x, &y);
	if (data->move.back || data->move.front
		|| data->move.left || data->move.right)
		i++;
	if (i >= ITEM_ANIM_DELAY)
		i = 0;
	x += ((double)WIN_WIDTH / 10) * 7;
	y += ((double)WIN_HEIGHT / 10) * 2;
	draw_item_to_img(data, x, y);
	return (0);
}
