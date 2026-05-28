/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 20:21:33 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/29 02:53:33 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./player_private.h"

void	init_player(t_player *player)
{
	player->pos \
		= dvec3(map_player_pos().x + 0.5, map_player_pos().y + 0.5, 1.5);
	if (map_player_dir() == PLAYER_NORTH)
		player->dir = dvec3(0.0, 1.0, 0.0);
	else if (map_player_dir() == PLAYER_SOUTH)
		player->dir = dvec3(0.0, -1.0, 0.0);
	else if (map_player_dir() == PLAYER_WEST)
		player->dir = dvec3(-1.0, 0.0, 0.0);
	else
		player->dir = dvec3(1.0, 0.0, 0.0);
	player->right = calc_player_right(player->dir);
	player->up = calc_player_up(player->right, player->dir);
}
