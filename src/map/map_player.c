/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 23:19:43 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/28 23:32:19 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./map_private.h"

static struct s_map_player	g_map_player;

void	set_map_player(t_ivec2 pos, char dir)
{
	g_map_player.pos = pos;
	g_map_player.dir = dir;
	g_map_player.is_set = true;
}

t_ivec2	map_player_pos(void)
{
	return (g_map_player.pos);
}

char	map_player_dir(void)
{
	return (g_map_player.dir);
}

bool	has_map_player(void)
{
	return (g_map_player.is_set);
}
