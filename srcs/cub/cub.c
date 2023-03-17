/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:00:51 by lgillard          #+#    #+#             */
/*   Updated: 2023/03/08 18:05:50 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	print_error(char *s1, char *s2)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(s1, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(s2, 2);
}

static int	open_cub(char *path)
{
	int	fd;

	if (!ft_strnstr(path + ft_strlen(path) - 4, ".cub", 4))
		return (ft_putstr_fd(INV_FILE, 2), -1);
	fd = open(path, O_DIRECTORY);
	if (fd != -1)
		return (print_error(path, "is a directory"), close(fd), -1);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (print_error(path, strerror(errno)), -1);
	return (fd);
}

// dirxy
// planexy
void	set_starting_direction(t_data *data, int x, int y)
{
	if (data->map[y][x] == 'N')
		data->ray.diry = -1;
	else if (data->map[y][x] == 'S')
		data->ray.diry = 1;
	else if (data->map[y][x] == 'W')
		data->ray.dirx = -1;
	else if (data->map[y][x] == 'E')
		data->ray.dirx = 1;
	if (data->ray.diry == -1)
		data->ray.planex = 0.66;
	else if (data->ray.diry == 1)
		data->ray.planex = -0.66;
	else if (data->ray.dirx == -1)
		data->ray.planey = -0.66;
	else if (data->ray.dirx == 1)
		data->ray.planey = 0.66;
}

// posxy
// mapxy
void	set_starting_pos(t_data *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1')
			{
				data->ray.posx = j + 0.5;
				data->ray.posy = i + 0.5;
				data->ray.mapx = j;
				data->ray.mapy = i;
				set_starting_direction(data, j, i);
			}
			j++;
		}
		i++;
	}
}

int	parse_cub(char *path, t_data *data)
{
	int	fd;

	fd = open_cub(path);
	if (fd == -1)
		return (1);
	if (fill_textures_and_colors(data, fd))
		return (close(fd), 1);
	if (fill_map(data, fd))
		return (close(fd), 1);
	close(fd);
	if (!is_map_valid(data->map))
		return (1);
	set_starting_pos(data, data->map);
	data->map[data->ray.mapy][data->ray.mapx] = '0';
	return (0);
}
