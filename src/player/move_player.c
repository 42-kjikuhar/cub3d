/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 00:21:15 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/28 23:15:58 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./player_private.h"

void	move_player(t_player *player, t_dvec3 move);

void	move_player_forward(t_player *player)
{
	t_dvec3	move;

	move = dvec3_scale(MOVE_SPEED, dvec3(player->dir.x, player->dir.y, 0));
	move_player(player, move);
}

void	move_player_left(t_player *player)
{
	t_dvec3	dir;
	t_dvec3	move;

	dir = dvec3_rotate_z(dvec3(player->dir.x, player->dir.y, 0), -90.0);
	move = dvec3_scale(MOVE_SPEED, dir);
	move_player(player, move);
}

void	move_player_back(t_player *player)
{
	t_dvec3	dir;
	t_dvec3	move;

	dir = dvec3_rotate_z(dvec3(player->dir.x, player->dir.y, 0), 180.0);
	move = dvec3_scale(MOVE_SPEED, dir);
	move_player(player, move);
}

void	move_player_right(t_player *player)
{
	t_dvec3	dir;
	t_dvec3	move;

	dir = dvec3_rotate_z(dvec3(player->dir.x, player->dir.y, 0), 90.0);
	move = dvec3_scale(MOVE_SPEED, dir);
	move_player(player, move);
}

void	move_player(t_player *player, t_dvec3 move)
{
	t_dvec3	new_pos;

	new_pos = dvec3_add(player->pos, move);
	if (is_colliding_with_wall(dvec3(new_pos.x, player->pos.y, player->pos.z)))
	{
		new_pos.x = player->pos.x;
	}
	if (is_colliding_with_wall(dvec3(player->pos.x, new_pos.y, player->pos.z)))
	{
		new_pos.y = player->pos.y;
	}
	if (new_pos.x != player->pos.x && new_pos.y != player->pos.y \
		&& is_colliding_with_wall(dvec3(new_pos.x, new_pos.y, player->pos.z)))
	{
		return ;
	}
	player->pos = new_pos;
}
