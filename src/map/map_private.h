/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_private.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 22:01:10 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/28 23:50:47 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PRIVATE_H
# define MAP_PRIVATE_H

#include "types.h"

struct	s_map_player
{
	t_ivec2	pos;
	char	dir;
	bool	is_set;
};

void	set_map_size(int x_size, int y_size);

#endif
