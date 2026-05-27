/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_wall_point.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 20:36:36 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/27 20:48:52 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../drawer_private.h"

// intのオーバーフローを考慮できていない。
void	compute_wall_point(t_player const *player, t_dvec3 to_point, \
								double *point_depth, int *point_screen_height)
{
	double	dot;

	*point_depth = player->dir.x * to_point.x + player->dir.y * to_point.y;
	dot = dvec3_dot(to_point, player->up) \
			/ (player->screen_half_height * *point_depth);
	*point_screen_height = (int)round(((1.0 - dot) / 2.0) * W_HEIGHT);
}
