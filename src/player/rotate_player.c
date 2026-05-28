/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 00:32:08 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/29 02:52:43 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./player_private.h"

void	rotate_player_left(t_player *player)
{
	player->dir = dvec3_rotate_z(player->dir, -1.0);
	player->right = calc_player_right(player->dir);
	player->up = calc_player_up(player->right, player->dir);
	change_camera_dir(player->dir);
}

void	rotate_player_right(t_player *player)
{
	player->dir = dvec3_rotate_z(player->dir, 1.0);
	player->right = calc_player_right(player->dir);
	player->up = calc_player_up(player->right, player->dir);
	change_camera_dir(player->dir);
}

// ロドリゲス回転公式
void	rotate_player_up(t_player *player)
{
	double const	radian = 1.0 * DEG_TO_RAD;
	double const	s = sin(radian);
	double const	c = cos(radian);

	player->dir = dvec3_add(\
		dvec3_scale(c, player->dir), dvec3_scale(s, player->up));
	player->right = calc_player_right(player->dir);
	player->up = calc_player_up(player->right, player->dir);
	change_camera_dir(player->dir);
}

void	rotate_player_down(t_player *player)
{
	double const	radian = -1.0 * DEG_TO_RAD;
	double const	s = sin(radian);
	double const	c = cos(radian);

	player->dir = dvec3_add(\
		dvec3_scale(c, player->dir), dvec3_scale(s, player->up));
	player->right = calc_player_right(player->dir);
	player->up = calc_player_up(player->right, player->dir);
	change_camera_dir(player->dir);
}
