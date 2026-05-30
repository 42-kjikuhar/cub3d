/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 18:37:35 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/30 13:26:01 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./parse_map_private.h"

bool	parse_map_data(void)
{
	int	x;
	int	y;

	y = 0;
	while (y < get_map_size(Y_AXIS))
	{
		x = 0;
		while (x < get_map_size(X_AXIS))
		{
			if (!parse_map_cell(x, y))
				return (false);
			++x;
		}
		++y;
	}
	if (!(get_map_player()->is_set))
	{
		print_error(ERROR_MAP_NO_PLAYER);
		return (false);
	}
	return (true);
}
