/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:58:46 by dly               #+#    #+#             */
/*   Updated: 2023/03/10 10:21:46 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	frame(t_data *data)
{
	update_player_position_and_direction(data);
	background(data);
	raycasting(data);
	minimap(data);
	draw_item(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}

int	init_img(t_data *data)
{	
	data->img.img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img.img)
		return (free_data(data), perror("mlx_new_image"), 1);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	if (!data->img.addr)
		return (free_data(data), perror("mlx_get_data_addr"), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	if (argc != 2)
		return (ft_putstr_fd(INV_ARGS, 2), 1);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (perror("mlx_init"), 1);
	if (parse_cub(argv[1], &data))
		return (free_data(&data), 1);
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!data.win)
		return (free_data(&data), perror("mlx_new_window"), 1);
	if (init_img(&data))
		return (1);
	if (load_item(&data))
		return (1);
	mlx_loop_hook(data.mlx, frame, &data);
	mlx_hook(data.win, 2, 1L << 0, key_down_handler, &data);
	mlx_hook(data.win, 3, 1L << 1, key_up_handler, &data);
	mlx_hook(data.win, 6, 1L << 6, mouse_move_handler, &data);
	mlx_hook(data.win, 17, 0, end_game, &data);
	mlx_loop(data.mlx);
}
