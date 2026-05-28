/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 18:36:09 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/28 22:25:21 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./parse_map_private.h"

bool	parse_map(int fd)
{
	if (!read_map(fd))
		return (false);
	if (!parse_map_data())
	{
		cleanup_map();
		return (false);
	}
	return (true);
}
