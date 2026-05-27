/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   depth_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 19:03:45 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/27 19:16:47 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	g_depth_buffer[W_HEIGHT][W_WIDTH];

void	clear_depth_buffer(void)
{
	int	x;
	int	y;

	y = 0;
	while (y < W_HEIGHT)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			g_depth_buffer[y][x++] = INFINITY;
		}
		++y;
	}
}

bool	try_depth_buffer(double depth, int x, int y)
{
	if (depth >= g_depth_buffer[y][x])
		return (false);
	g_depth_buffer[y][x] = depth;
	return (true);
}
