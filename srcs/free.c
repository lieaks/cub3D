/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillard <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:01:17 by lgillard          #+#    #+#             */
/*   Updated: 2023/03/09 21:48:11 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	free_textures(t_data *data)
{
	if (data->no.img)
		mlx_destroy_image(data->mlx, data->no.img);
	if (data->so.img)
		mlx_destroy_image(data->mlx, data->so.img);
	if (data->we.img)
		mlx_destroy_image(data->mlx, data->we.img);
	if (data->ea.img)
		mlx_destroy_image(data->mlx, data->ea.img);
	if (data->item.img)
		mlx_destroy_image(data->mlx, data->item.img);
	return (0);
}

int	free_data(t_data *data)
{
	free_textures(data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->map)
		ft_free_tab(data->map);
	return (0);
}

int	end_game(t_data *data)
{
	free_data(data);
	exit(EXIT_SUCCESS);
}
