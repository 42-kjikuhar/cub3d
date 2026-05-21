/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dvec3_normalize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 22:08:06 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/21 22:42:13 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector/dvec3.h"

t_dvec3	dvec3_normalize(t_dvec3 v)
{
	return (dvec3_scale(1 / dvec3_length(v), v));
}
