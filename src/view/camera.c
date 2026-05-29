/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 00:03:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/29 13:40:46 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./view_private.h"

static t_camera	g_camera;

t_camera const	*camera(void)
{
	return (&g_camera);
}

void	set_camera(t_dvec3 pos, t_dvec3 dir)
{
	g_camera.pos = pos;
	g_camera.dir = dir;
	g_camera.right = calc_camera_right(g_camera.dir);
	g_camera.up = calc_camera_up(g_camera.right, g_camera.dir);
	set_screen_horizontal_pixel(&g_camera);
}

void	set_camera_lookat(t_dvec3 look_from, t_dvec3 look_at)
{
	g_camera.pos = look_from;
	g_camera.dir = dvec3_sub(look_at, look_from);
	g_camera.right = calc_camera_right(g_camera.dir);
	g_camera.up = calc_camera_up(g_camera.right, g_camera.dir);
	set_screen_horizontal_pixel(&g_camera);
}

void	change_camera_pos(t_dvec3 pos)
{
	g_camera.pos = pos;
}

void	change_camera_dir(t_dvec3 dir)
{
	g_camera.dir = dir;
	g_camera.right = calc_camera_right(g_camera.dir);
	g_camera.up = calc_camera_up(g_camera.right, g_camera.dir);
	set_screen_horizontal_pixel(&g_camera);
}
