/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dvec3_scale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 22:08:06 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/21 22:34:04 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector/dvec3.h"

t_dvec3	dvec3_scale(double s, t_dvec3 v)
{
	t_dvec3	u;

	u.x = s * v.x;
	u.y = s * v.y;
	u.z = s * v.z;
	return (u);
}
