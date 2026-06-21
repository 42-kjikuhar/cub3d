/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dvec3_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 18:55:47 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/06/21 19:19:20 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dvec3.h"
#include "cub3d.h"

/* r' = r cos + (1 - cos) * dot(r, axis)axis + cross(axis, r)sin*/
t_dvec3	dvec3_rotate(t_dvec3 v, t_dvec3 axis, double degree)
{
	double const	theta = degree * DEG_TO_RAD;


	return (dvec3_add(dvec3_add(\
		dvec3_scale(cos(theta), v), \
		dvec3_scale((1 - cos(theta)) * dvec3_dot(v, axis), axis)), \
	dvec3_scale(sin(theta), dvec3_cross(axis, v))));
}
