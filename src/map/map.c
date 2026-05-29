/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 21:34:47 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/29 13:02:12 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**g_map;

char	map(int x, int y)
{
	return (g_map[y][x]);
}

void	set_map(char data, int x, int y)
{
	g_map[y][x] = data;
}

bool	allocate_map(int x_size, int y_size)
{
	int	y;

	g_map = malloc(sizeof(char *) * y_size);
	if (g_map == NULL)
	{
		print_error(strerror(errno));
		return (false);
	}
	y = 0;
	while (y < y_size)
	{
		g_map[y] = malloc(sizeof(char) * x_size);
		if (g_map[y] == NULL)
		{
			while (--y >= 0)
				free(g_map[y]);
			free(g_map);
			g_map = NULL;
			print_error(strerror(errno));
			return (false);
		}
		++y;
	}
	set_map_size(x_size, y_size);
	return (true);
}

void	cleanup_map(void)
{
	int	y;

	if (g_map == NULL)
		return ;
	y = map_size(Y_AXIS);
	while (y-- > 0)
		free(g_map[y]);
	free(g_map);
	g_map = NULL;
}
