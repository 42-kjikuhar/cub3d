/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ivec2_sub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 13:11:40 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/21 22:46:18 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector/ivec2.h"

t_ivec2	ivec2_sub(t_ivec2 a, t_ivec2 b)
{
	t_ivec2	diff;

	diff.x = a.x - b.x;
	diff.y = a.y - b.y;
	return (diff);
}
