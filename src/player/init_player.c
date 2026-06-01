/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 20:21:33 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/01 03:29:04 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./player_private.h"

void	init_player(t_map_player const *map_player)
{
	change_player_pos(\
		dvec3(map_player->pos.x + 0.5, map_player->pos.y + 0.5, 1.5));
	if (map_player->dir == PLAYER_NORTH)
		change_player_dir(dvec3(0.0, 1.0, 0.0));
	else if (map_player->dir == PLAYER_SOUTH)
		change_player_dir(dvec3(0.0, -1.0, 0.0));
	else if (map_player->dir == PLAYER_WEST)
		change_player_dir(dvec3(-1.0, 0.0, 0.0));
	else
		change_player_dir(dvec3(1.0, 0.0, 0.0));
}
