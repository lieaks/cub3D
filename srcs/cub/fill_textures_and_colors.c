/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_textures_and_colors.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:49:29 by mirsella          #+#    #+#             */
/*   Updated: 2023/03/07 18:34:36 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"
#include <stdio.h>

static int	load_textures(t_data *data, char *line)
{
	int		height;
	int		width;
	void	**texture;

	if (ft_strncmp(line, "NO ", 3) == 0)
		texture = &data->no.img;
	else if (ft_strncmp(line, "SO ", 3) == 0)
		texture = &data->so.img;
	else if (ft_strncmp(line, "WE ", 3) == 0)
		texture = &data->we.img;
	else if (ft_strncmp(line, "EA ", 3) == 0)
		texture = &data->ea.img;
	else
		return (ft_putstr_fd(INV_FILE_LINE, 2), 1);
	if (*texture)
		return (errno = EEXIST, 1);
	*texture = mlx_xpm_file_to_image(data->mlx,
			line + 3 + ft_skip_spaces(line + 3), &width, &height);
	if (!*texture)
		return (print_error(line + 3 + ft_skip_spaces(line + 3),
				strerror(errno)), 1);
	return (0);
}

static int	split_color(char *line, int *colors)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(line, ", ");
	if (!split)
		return (perror("malloc"), 1);
	while (split[i])
		i++;
	if (i != 3)
		return (print_error(line, "Invalid no 3 numbers separated by ,"),
			ft_free_tab(split), 1);
	i = 0;
	while (i < 3)
	{
		colors[i] = ft_atoi(split[i]);
		if (colors[i] < 0 || colors[i] > 255 || !ft_isdigit(split[i][0]))
			return (print_error(line, INV_COLOR_RANGE),
				ft_free_tab(split), 1);
		i++;
	}
	ft_free_tab(split);
	return (0);
}

static int	handle_line(t_data *data, char *line)
{
	if (ft_strncmp(line, "C ", 2) == 0)
	{
		if (split_color(line + 2, data->color_ceiling))
			return (1);
	}
	else if (ft_strncmp(line, "F ", 2) == 0)
	{
		if (split_color(line + 2, data->color_floor))
			return (1);
	}
	else
		if (load_textures(data, line))
			return (1);
	return (0);
}

int	are_all_textures_loaded(t_data *data)
{
	if (!data->no.img || !data->so.img
		|| !data->we.img || !data->ea.img
		|| data->color_ceiling[0] == -1
		|| data->color_floor[0] == -1)
		return (0);
	return (1);
}

int	fill_textures_and_colors(t_data *data, int fd)
{
	char	*line;

	line = "";
	ft_memset(data->color_ceiling, -1, sizeof(int) * 3);
	ft_memset(data->color_floor, -1, sizeof(int) * 3);
	while (are_all_textures_loaded(data) == 0)
	{
		line = ft_get_next_line(fd, 0);
		if (!line)
			return (ft_putstr_fd(INV_FILE, 2), 1);
		if (*line && *line != '\n')
		{
			line[ft_strlen(line) - 1] = '\0';
			if (handle_line(data, line))
				return (free(line), ft_get_next_line(fd, 1), 1);
		}
		free(line);
	}
	return (0);
}
