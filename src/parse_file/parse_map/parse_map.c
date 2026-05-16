/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 18:36:09 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/16 18:38:01 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



bool	parse_map(int fd, t_map *map)
{
	if (!read_map(fd, map))
	{
		print_error();
		return (false);
	}
	if (!parse_map_data(map))
	{
		free_map(map);
		return (false);
	}
	return (true);

}
