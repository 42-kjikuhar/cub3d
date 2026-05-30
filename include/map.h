/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 22:01:14 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/30 13:25:45 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdbool.h>

# include "types.h"
# include "vector/ivec2.h"

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

struct	s_map_player
{
	char	dir;
	t_ivec2	pos;
	bool	is_set;
};

char				get_map_data(int x, int y);
void				set_map_data(int x, int y, char data);
bool				allocate_map(int x_size, int y_size);
void				cleanup_map(void);
int					get_map_size(enum e_axis axis);
void				set_map_size(int x_size, int y_size);
bool				is_map_outside(int x, int y);
t_map_player const	*get_map_player(void);
void				set_map_player(char dir, t_ivec2 pos);

#endif
