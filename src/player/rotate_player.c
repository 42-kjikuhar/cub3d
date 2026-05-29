/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 00:32:08 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/29 13:32:37 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./player_private.h"

void	rotate_player_left(void)
{
	change_player_dir(dvec3_rotate_z(player()->dir, -1.0));
	change_camera_dir(player()->dir);
}

void	rotate_player_right(void)
{
	change_player_dir(dvec3_rotate_z(player()->dir, 1.0));
	change_camera_dir(player()->dir);
}

// ロドリゲス回転公式
void	rotate_player_up(void)
{
	double const	radian = 1.0 * DEG_TO_RAD;
	double const	s = sin(radian);
	double const	c = cos(radian);

	change_player_dir(dvec3_add(\
		dvec3_scale(c, player()->dir), dvec3_scale(s, player()->up)));
	change_camera_dir(player()->dir);
}

void	rotate_player_down(void)
{
	double const	radian = -1.0 * DEG_TO_RAD;
	double const	s = sin(radian);
	double const	c = cos(radian);

	change_player_dir(dvec3_add(\
		dvec3_scale(c, player()->dir), dvec3_scale(s, player()->up)));
	change_camera_dir(player()->dir);
}
