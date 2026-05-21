/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ivec2_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 13:11:40 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/21 22:46:12 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector/ivec2.h"

t_ivec2	ivec2_add(t_ivec2 a, t_ivec2 b)
{
	t_ivec2	sum;

	sum.x = a.x + b.x;
	sum.y = a.y + b.y;
	return (sum);
}
