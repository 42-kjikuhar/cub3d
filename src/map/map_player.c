/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 23:19:43 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/30 13:20:12 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_map_player	g_map_player;

t_map_player const	*get_map_player(void)
{
	return (&g_map_player);
}

void	set_map_player(char dir, t_ivec2 pos)
{
	g_map_player.dir = dir;
	g_map_player.pos = pos;
	g_map_player.is_set = true;
}
