/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 21:51:27 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/19 21:53:11 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cleanup_map(t_map *map)
{
	int		y;

	if (map->data == NULL)
		return ;
	y = 0;
	while (y < map->y_size)
	{
		free(map->data[y]);
	}
	free(map->data);
}
