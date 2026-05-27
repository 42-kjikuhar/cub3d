/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 22:42:23 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/27 22:42:53 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_player *player, t_map const *map)
{
	double	plane_length;

	player->pos = dvec3(map->player_pos.x + 0.5, map->player_pos.y + 0.5, 0.5);
	plane_length = tan(DEG_TO_RAD * FOV * 0.5);
	if (map->player_dir == PLAYER_NORTH)
	{
		player->dir = dvec3(0, -1, 0);
		player->plane = dvec3(plane_length, 0, 0);
	}
	else if (map->player_dir == PLAYER_SOUTH)
	{
		player->dir = dvec3(0, 1, 0);
		player->plane = dvec3(-plane_length, 0, 0);
	}
	else if (map->player_dir == PLAYER_WEST)
	{
		player->dir = dvec3(-1, 0, 0);
		player->plane = dvec3(0, plane_length, 0);
	}
	else if (map->player_dir == PLAYER_EAST)
	{
		player->dir = dvec3(1, 0, 0);
		player->plane = dvec3(0, -plane_length, 0);
	}
}
