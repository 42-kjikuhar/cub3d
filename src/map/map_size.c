/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 21:57:53 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/28 22:55:49 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	g_map_size[2];

int	map_size(enum e_axis axis)
{
	return (g_map_size[axis]);
}

void	set_map_size(int x_size, int y_size)
{
	g_map_size[X_AXIS] = x_size;
	g_map_size[Y_AXIS] = y_size;
}

bool	is_map_outside(int x, int y)
{
	return (x < 0 || g_map_size[X_AXIS] <= x \
			|| y < 0 || g_map_size[Y_AXIS] <= y);
}
