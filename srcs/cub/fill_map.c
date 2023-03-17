/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:37:37 by mirsella          #+#    #+#             */
/*   Updated: 2023/03/09 13:41:57 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	get_line_and_realloc(t_data *data, char **line, int i, int fd)
{
	data->map = ft_realloc(data->map,
			sizeof(char *) * (i + 1), sizeof(char *) * (i + 2));
	if (!data->map)
		return (ft_get_next_line(fd, 1), perror("malloc"), -1);
	*line = ft_get_next_line(fd, 0);
	return (0);
}

int	fill_map_from_fd(t_data *data, int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = ft_strdup("");
	while (line)
	{
		free(line);
		if (get_line_and_realloc(data, &line, i, fd))
			return (1);
		if (!line)
			return (0);
		if (i == 0 && (size_t)ft_skip_spaces(line) == ft_strlen(line))
			continue ;
		if (*(line + ft_skip_spaces(line)) == '\0')
			return (ft_get_next_line(fd, 1), free(line),
				ft_putstr_fd(INV_EMPTY_LINE, 2), 1);
		line[ft_strlen(line) - 1] = '\0';
		data->map[i++] = line;
		data->map[i] = NULL;
		line = ft_strdup("");
	}
	if (i == 0)
		return (ft_putstr_fd(INV_MAP, 2), 1);
	return (0);
}

int	resize_matrix(char **map)
{
	size_t	i;
	size_t	max;

	i = 0;
	max = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) > max)
			max = ft_strlen(map[i]);
		i++;
	}
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) < max)
		{
			map[i] = ft_realloc(map[i], ft_strlen(map[i]) + 1, max + 1);
			if (!map[i])
				return (perror("malloc"), -1);
			ft_memset(map[i] + ft_strlen(map[i]), ' ', max - ft_strlen(map[i]));
			map[i][max] = '\0';
		}
		i++;
	}
	return (0);
}

void	fill_spaces_and_set_size(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == ' ')
				data->map[i][j] = '0';
			j++;
		}
		i++;
	}
	data->map_width = ft_strlen(data->map[0]);
	data->map_height = i;
}

int	fill_map(t_data *data, int fd)
{
	if (fill_map_from_fd(data, fd))
		return (1);
	if (resize_matrix(data->map))
		return (1);
	fill_spaces_and_set_size(data);
	return (0);
}
