/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:12:54 by dly               #+#    #+#             */
/*   Updated: 2023/03/13 09:01:44 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

// WINDOW SIZE
# define WIN_WIDTH	1920
# define WIN_HEIGHT	1080

# define ROT_SPEED 0.07
# define MOUSE_SPEED 0.005
# define MOVE_SPEED 0.12

// TEXTURE
# define TEXTURE_SIZE 64
// 1 pixel in xpm -> 4 on the img
# define ITEM_SIZE_FACTOR 3
# define ITEM_ANIM_DELAY 60

// PIXEL PER CHARACTER: 10 pixel for one character in the map
# define MINIMAP_PPC 10
# define MINIMAP_SIZE 16
# define MINIMAP_WALL_COLOR 0x00000000
# define MINIMAP_PLAYER_COLOR 0xCB0E00
# define MINIMAP_FLOOR_COLOR 0x00FFFFFF

// COLOR
# define BLACK 0x0000000
# define WHITE 0xffffff
# define YELLOW 0xEEEE20
# define RED 0xCB0E00
# define GREEN 0x609F1C
# define PURPLE 0xFF00FF

# define ITEM_PATH "textures/item.xpm"

// ERROR MSG
# define INV_ARGS "Error\nUse : ./cub3D \"<map.cub>\"\n"
# define INV_FILE "Error\nInvalid file type, please use .cub\n"
# define INV_FILE_LINE "Error\nInvalid line\n"
# define INV_EMPTY_LINE "Error\nEmpty line in map\n"
# define INV_BORDERS "Error\nInvalid borders\n"
# define INV_PLAYER_NB "Invalid number of players"
# define INV_CHAR "Invalid character"
# define INV_MAP "Error\nInvalid map.\n"
# define INV_COLOR_RANGE "Invalid color,\
 not a number between 0 and 255.\n"

#endif
