/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dvec3_rotate_y.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 01:09:36 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/27 01:41:15 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// left hand coordinate system
t_dvec3	dvec3_rotate_y(t_dvec3 v, double degree)
{
	double const	radian = degree * DEG_TO_RAD;
	double const	s = sin(radian);
	double const	c = cos(radian);

	return ((t_dvec3){\
		v.x * c + v.z * -s, \
		v.y, \
		v.x * s + v.z * c \
	});
}
