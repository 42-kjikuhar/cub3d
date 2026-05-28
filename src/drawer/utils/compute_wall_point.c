/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_wall_point.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 20:36:36 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/29 02:44:07 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../drawer_private.h"

// intのオーバーフローを考慮できていない。
void	compute_wall_point(t_dvec3 to_point, \
								double *point_depth, int *point_screen_height)
{
	t_camera const	*cam = camera();
	double			dot;

	*point_depth = cam->dir.x * to_point.x + cam->dir.y * to_point.y;
	dot = dvec3_dot(to_point, cam->up) \
			/ (screen()->half_height * *point_depth);
	*point_screen_height = (int)round(((1.0 - dot) / 2.0) * W_HEIGHT);
}
