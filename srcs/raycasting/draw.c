/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:05:54 by dly               #+#    #+#             */
/*   Updated: 2023/03/10 11:43:40 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	define_col(t_data *data)
{
	data->ray.lineheight = (int)(WIN_HEIGHT / data->ray.perpwalldist);
	data->ray.drawstart = -data->ray.lineheight / 2 + (int)WIN_HEIGHT / 2;
	if (data->ray.drawstart < 0)
		data->ray.drawstart = 0;
	data->ray.drawend = data->ray.lineheight / 2 + (int)WIN_HEIGHT / 2;
	if (data->ray.drawend >= WIN_HEIGHT)
		data->ray.drawend = WIN_HEIGHT - 1;
	return (0);
}

int	define_texture(t_data *data)
{
	if (data->ray.side == 0)
	{
		data->ray.wallx = data->ray.posy
			+ data->ray.perpwalldist * data->ray.raydiry;
	}
	else
		data->ray.wallx = data->ray.posx
			+ data->ray.perpwalldist * data->ray.raydirx;
	data->ray.wallx -= floor(data->ray.wallx);
	data->ray.texx = (int)(data->ray.wallx * (double)(TEXTURE_SIZE));
	if (data->ray.side == 0 && data->ray.raydirx > 0)
		data->ray.texx = TEXTURE_SIZE - data->ray.texx - 1;
	if (data->ray.side == 1 && data->ray.raydiry < 0)
		data->ray.texx = TEXTURE_SIZE - data->ray.texx - 1;
	data->ray.step = 1.0 * TEXTURE_SIZE / data->ray.lineheight;
	data->ray.texpos = (data->ray.drawstart - (double)WIN_HEIGHT / 2
			+ (double)data->ray.lineheight / 2) * data->ray.step;
	return (0);
}

int	draw(t_data *data, t_img *img)
{
	int	color;

	color = get_color_pixel(img->img, data->ray.texx, data->ray.texy);
	my_mlx_pixel_put(&data->img, data->ray.x, data->ray.drawstart, color);
	return (0);
}

int	draw_col(t_data *data)
{
	define_col(data);
	define_texture(data);
	while (data->ray.drawstart < data->ray.drawend)
	{
		data->ray.texy = (int)data->ray.texpos & (TEXTURE_SIZE - 1);
		data->ray.texpos += data->ray.step;
		if (data->ray.side == 1 && data->ray.raydiry < 0)
			draw(data, &data->so);
		else if (data->ray.side == 1 && data->ray.raydiry > 0)
			draw(data, &data->no);
		else if (data->ray.side == 0 && data->ray.raydirx < 0)
			draw(data, &data->we);
		else if (data->ray.side == 0 && data->ray.raydirx > 0)
			draw(data, &data->ea);
		data->ray.drawstart++;
	}
	return (0);
}
