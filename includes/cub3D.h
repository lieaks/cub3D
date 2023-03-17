/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:03:45 by dly               #+#    #+#             */
/*   Updated: 2023/03/09 19:52:41 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h" // ft_*
# include "../mlx/mlx.h"
# include "struct.h" // struct
# include "define.h" // INV_* error messages
# include <stdlib.h> // EXIT_*
# include "unistd.h" // open()
# include <fcntl.h> // file control options
# include <X11/keysym.h> // For X11 keycodes XK_*
# include "errno.h" // errno
# include "string.h" // strerror
# include "stdio.h" // printf, perror
# include <limits.h> // INT_MAX
# include <math.h> // sin, cos, tan, fabs, sqrt

// main.c
int				end_game(t_data *data);

// free.c
int				free_textures(t_data *data);
int				free_data(t_data *data);

// cub/cub.c
void			print_error(char *s1, char *s2);
int				parse_cub(char *path, t_data *data);

// map/fill_textures_and_colors.c
int				fill_textures_and_colors(t_data *data, int fd);

// map/fill_map.c
int				fill_map(t_data *data, int fd);

// map/map_checking.c
int				is_map_valid(char **map);

// key_hook.c
int				key_down_handler(int keycode, t_data *data);
int				key_up_handler(int keycode, t_data *data);
int				mouse_move_handler(int x, int y, t_data *data);

// move_player.c
int				move_front(t_data *data);
int				move_back(t_data *data);
int				move_left(t_data *data);
int				move_right(t_data *data);
int				update_player_position_and_direction(t_data *data);

// rotate_player.c
int				rotate_right(t_data *data);
int				rotate_left(t_data *data);

// raycasting/ft_put_pixel.c
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
unsigned int	get_color_pixel(void *img, int x, int y);

// raycasting/dda.c
int				get_step(t_data *data);
int				dda(t_data *data);

// raycasting/raycasting.c
int				raycasting(t_data *data);

// raycasting/render.c
int				background(t_data *data);
int				get_rgb(int r, int g, int b);

// raycasting/minimap.c
int				minimap(t_data *data);

// raycasting/draw.c
int				draw_col(t_data *data);

// item.c
int				load_item(t_data *data);
int				draw_item(t_data *data);

#endif
