/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:49:00 by dly               #+#    #+#             */
/*   Updated: 2023/03/09 14:06:44 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	get_color_pixel(void *img, int x, int y)
{
	t_img			tmp;
	unsigned int	color;
	char			*src;

	tmp.addr = mlx_get_data_addr(img, &tmp.bits_per_pixel, &tmp.line_length,
			&tmp.endian);
	src = tmp.addr + (y * tmp.line_length + x * (tmp.bits_per_pixel / 8));
	color = *(unsigned int *)src;
	return (color);
}
