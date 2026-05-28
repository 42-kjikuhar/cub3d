/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 22:01:14 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/29 00:05:56 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "types.h"

# define MAP_FLOOR '0'
# define MAP_WALL '1'
# define MAP_BLANK ' '
# define PLAYER_NORTH 'N'
# define PLAYER_SOUTH 'S'
# define PLAYER_WEST 'W'
# define PLAYER_EAST 'E'

enum	e_axis
{
	X_AXIS,
	Y_AXIS,
};

char	map(int x, int y);
void	set_map(char data, int x, int y);
bool	allocate_map(int x_size, int y_size);
void	cleanup_map(void);
int		map_size(enum e_axis axis);
bool	is_map_outside(int x, int y);
void	set_map_player(t_ivec2 pos, char dir);
t_ivec2	map_player_pos(void);
char	map_player_dir(void);
bool	has_map_player(void);

#endif
