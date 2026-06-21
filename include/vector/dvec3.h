/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dvec3.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 22:13:19 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/06/21 19:19:46 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DVEC3_H
# define DVEC3_H

# include "types.h"

struct s_dvec3
{
	double	x;
	double	y;
	double	z;
};

t_dvec3	dvec3(double x, double y, double z);
t_dvec3	dvec3_add(t_dvec3 a, t_dvec3 b);
t_dvec3	dvec3_sub(t_dvec3 a, t_dvec3 b);
t_dvec3	dvec3_scale(double s, t_dvec3 v);
double	dvec3_dot(t_dvec3 a, t_dvec3 b);
t_dvec3	dvec3_cross(t_dvec3 a, t_dvec3 b);
double	dvec3_length(t_dvec3 v);
t_dvec3	dvec3_normalize(t_dvec3 v);
t_dvec3	dvec3_rotate(t_dvec3 v, t_dvec3 axis, double degree);

#endif
