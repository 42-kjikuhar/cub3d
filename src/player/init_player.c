/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 20:21:33 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/26 20:34:12 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./player_private.h"

void	init_player(t_player *player, t_map const *map)
{
	player->pos = dvec3(map->player_pos.x + 0.5, map->player_pos.y + 0.5, 0.5);
	if (map->player_dir == PLAYER_NORTH)
		player->dir = dvec3(0, -1, 0);
	else if (map->player_dir == PLAYER_SOUTH)
		player->dir = dvec3(0, 1, 0);
	else if (map->player_dir == PLAYER_WEST)
		player->dir = dvec3(-1, 0, 0);
	else
		player->dir = dvec3(1, 0, 0);
	player->right = calc_camera_right(player->dir);
	player->up = calc_camera_up(player->right, player->dir);
	player->aspect_ratio = (double)W_WIDTH / W_HEIGHT;
	player->half_screen_width = tan(FOV * 0.5 * DEG_TO_RAD);
	player->half_screen_height = player->half_screen_width / player->aspect_ratio;
}
