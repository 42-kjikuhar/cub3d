/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dvec3_rotate_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 01:00:59 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/27 01:41:03 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// left hand coordinate system
t_dvec3	dvec3_rotate_x(t_dvec3 v, double degree)
{
	double const	radian = degree * DEG_TO_RAD;
	double const	s = sin(radian);
	double const	c = cos(radian);

	return ((t_dvec3){\
		v.x, \
		v.y * c + v.z * s, \
		v.y * -s + v.z * c \
	});
}
