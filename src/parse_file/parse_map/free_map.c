/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 12:35:49 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/17 12:41:24 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_map *map)
{
	int		i;
	char	**data;

	if (map->data == NULL)
		return ;
	data = map->data;
	i = 0;
	while (i < map->y_size)
	{
		free(data[i]);
	}
	free(data);
}
