/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 00:42:52 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/30 13:18:51 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_screen	g_screen;

t_screen const	*get_screen(void)
{
	return (&g_screen);
}

void	set_screen(double horizontal_fov)
{
	g_screen.aspect_ratio = (double)W_WIDTH / W_HEIGHT;
	g_screen.half_width = tan(horizontal_fov * 0.5 * DEG_TO_RAD);
	g_screen.half_height = g_screen.half_width / g_screen.aspect_ratio;
}

void	compute_screen_horizontal_pixel(t_camera const *cam)
{
	double	height;
	double	sin_pitch;
	double	cos_pitch;
	double	tan_pitch;

	sin_pitch = cam->dir.z;
	cos_pitch = sqrt(cam->dir.x * cam->dir.x + cam->dir.y * cam->dir.y);
	tan_pitch = sin_pitch / cos_pitch;
	height = (W_HEIGHT / 2.0) \
		+ (W_HEIGHT / 2.0) * (tan_pitch / g_screen.half_height);
	if (height > W_HEIGHT - 1)
		g_screen.horizontal_pixel = W_HEIGHT - 0.5;
	else if (height < 0.0)
		g_screen.horizontal_pixel = -0.5;
	else
		g_screen.horizontal_pixel = height;
}
