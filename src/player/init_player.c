/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 22:42:23 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/06/21 17:32:57 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_dvec3	init_screen_size(void)
{
	t_dvec3 screen_size;

	double const screen_width = tan(FOV / 2);
	double const screen_height = screen_width / W_WIDTH * W_HEIGHT;
	return (dvec3(screen_width, screen_height, 0));
}

void	init_player(t_player *player, t_map const *map)
{
	double	plane_length;

	player->pos = dvec3(map->player_pos.x + 0.5, map->player_pos.y + 0.5, 0.5);
	plane_length = tan(DEG_TO_RAD * FOV * 0.5);
	if (map->player_dir == PLAYER_NORTH)
	{
		player->dir = dvec3(0, 1, 0);
		player->plane = dvec3(plane_length, 0, 0);
	}
	else if (map->player_dir == PLAYER_SOUTH)
	{
		player->dir = dvec3(0, -1, 0);
		player->plane = dvec3(-plane_length, 0, 0);
	}
	else if (map->player_dir == PLAYER_WEST)
	{
		player->dir = dvec3(-1, 0, 0);
		player->plane = dvec3(0, -plane_length, 0);
	}
	else if (map->player_dir == PLAYER_EAST)
	{
		player->dir = dvec3(1, 0, 0);
		player->plane = dvec3(0, plane_length, 0);
	}
	player->screen_size = init_screen_size();
}
