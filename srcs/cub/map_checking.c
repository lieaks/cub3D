/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:52:17 by mirsella          #+#    #+#             */
/*   Updated: 2023/03/10 10:04:40 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"
#include <stdio.h>

int	check_characters(char **map)
{
	int	i;
	int	j;
	int	nb_player;

	i = 0;
	nb_player = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
				nb_player++;
			else if (map[i][j] != '0' && map[i][j] != '1')
				return (print_error(INV_CHAR, (char []){map[i][j], 0}), 1);
			j++;
		}
		i++;
	}
	if (nb_player != 1)
		return (print_error(INV_PLAYER_NB, (char []){nb_player + '0', 0}), 1);
	return (0);
}

// flood fill algo with 2, return 1 if a 2 gets to the edge of the map
int	flood_recursively_to_border(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == '2')
		return (0);
	map[y][x] = '2';
	if (x == 0 || y == 0 || map[y + 1] == NULL || map[y][x + 1] == '\0')
		return (1);
	if (flood_recursively_to_border(map, x + 1, y))
		return (1);
	if (flood_recursively_to_border(map, x - 1, y))
		return (1);
	if (flood_recursively_to_border(map, x, y + 1))
		return (1);
	if (flood_recursively_to_border(map, x, y - 1))
		return (1);
	if (flood_recursively_to_border(map, x + 1, y + 1))
		return (1);
	if (flood_recursively_to_border(map, x - 1, y - 1))
		return (1);
	if (flood_recursively_to_border(map, x + 1, y - 1))
		return (1);
	if (flood_recursively_to_border(map, x - 1, y + 1))
		return (1);
	return (0);
}

int	is_player_surrounded(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
			{
				if (flood_recursively_to_border(map, j, i))
					return (ft_putstr_fd(INV_BORDERS, 2), 0);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	is_map_valid(char **map)
{
	char	**map_copy;

	if (check_characters(map))
		return (0);
	map_copy = ft_tabdup(map);
	if (!map_copy)
		return (perror("malloc"), 1);
	if (!is_player_surrounded(map_copy))
		return (ft_free_tab(map_copy), 0);
	ft_free_tab(map_copy);
	return (1);
}
