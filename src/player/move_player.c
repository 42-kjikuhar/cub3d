/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 00:21:15 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/29 13:32:01 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./player_private.h"

static void	move_player(t_dvec3 move);

void	move_player_forward(void)
{
	t_dvec3	move;

	move = dvec3_scale(MOVE_SPEED, player()->dir);
	move.z = 0.0;
	move_player(move);
	change_camera_pos(player()->pos);
}

void	move_player_left(void)
{
	t_dvec3	move;

	move = dvec3_scale(MOVE_SPEED, dvec3_rotate_z(player()->dir, -90.0));
	move.z = 0.0;
	move_player(move);
	change_camera_pos(player()->pos);
}

void	move_player_back(void)
{
	t_dvec3	move;

	move = dvec3_scale(MOVE_SPEED, dvec3_rotate_z(player()->dir, 180.0));
	move.z = 0.0;
	move_player(move);
	change_camera_pos(player()->pos);
}

void	move_player_right(void)
{
	t_dvec3	move;

	move = dvec3_scale(MOVE_SPEED, dvec3_rotate_z(player()->dir, 90.0));
	move.z = 0.0;
	move_player(move);
	change_camera_pos(player()->pos);
}

static void	move_player(t_dvec3 move)
{
	t_dvec3	pos;
	t_dvec3	new_pos;

	pos = player()->pos;
	new_pos = dvec3_add(pos, move);
	if (is_colliding_with_wall(dvec3(new_pos.x, pos.y, pos.z)))
	{
		new_pos.x = pos.x;
	}
	if (is_colliding_with_wall(dvec3(pos.x, new_pos.y, pos.z)))
	{
		new_pos.y = pos.y;
	}
	if (new_pos.x != pos.x && new_pos.y != pos.y \
		&& is_colliding_with_wall(dvec3(new_pos.x, new_pos.y, pos.z)))
	{
		return ;
	}
	change_player_pos(new_pos);
}
