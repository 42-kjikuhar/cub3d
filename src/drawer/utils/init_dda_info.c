/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dda_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 17:57:47 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/30 13:18:39 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../drawer_private.h"

static void	compute_initial_dist( t_dda *dda);

t_dda	init_dda_info(int win_x)
{
	t_camera const	*cam = get_camera();
	t_dda			dda;
	double			t;

	dda.origin = dvec3(cam->pos.x, cam->pos.y, 0.0);
	t = (((double)win_x / W_WIDTH) - 0.5) * 2.0;
	dda.ray = dvec3_add(cam->dir, \
				dvec3_scale(t * get_screen()->half_width, cam->right));
	dda.ray.z = 0.0;
	dda.ray = dvec3_normalize(dda.ray);
	dda.delta_dist_x = fabs(1.0 / dda.ray.x);
	dda.delta_dist_y = fabs(1.0 / dda.ray.y);
	compute_initial_dist(&dda);
	dda.cell = ivec2((int)(dda.origin.x), (int)(dda.origin.y));
	if (dda.ray.x > 0)
		dda.cell_step.x = 1;
	else
		dda.cell_step.x = -1;
	if (dda.ray.y > 0)
		dda.cell_step.y = 1;
	else
		dda.cell_step.y = -1;
	dda.delta_height_x = cam->dir.z / dda.ray.x;
	dda.delta_height_y = cam->dir.z / dda.ray.y;
	return (dda);
}

static void	compute_initial_dist(t_dda *dda)
{
	if (dda->ray.x > 0)
	{
		dda->dist_x \
			= (ceil(dda->origin.x) - dda->origin.x) * dda->delta_dist_x;
	}
	else
	{
		dda->dist_x \
			= (dda->origin.x - floor(dda->origin.x)) * dda->delta_dist_x;
	}
	if (dda->ray.y > 0)
	{
		dda->dist_y \
			= (ceil(dda->origin.y) - dda->origin.y) * dda->delta_dist_y;
	}
	else
	{
		dda->dist_y \
			= (dda->origin.y - floor(dda->origin.y)) * dda->delta_dist_y;
	}
}
