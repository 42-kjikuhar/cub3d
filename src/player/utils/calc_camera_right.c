/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_camera_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 20:21:43 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/26 21:07:42 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// left hand coordinate system
t_dvec3	calc_camera_right(t_dvec3 dir)
{
	static t_dvec3 const    vup = (t_dvec3){.x=0.0, .y=0.0, .z=1.0};

	return (dvec3_normalize(dvec3_cross(dir, vup)));
}
