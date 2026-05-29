/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:02:21 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/29 13:53:47 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_view(double horizontal_fov, t_dvec3 pos, t_dvec3 dir)
{
	set_screen(horizontal_fov);
	set_camera(pos, dir);
}
