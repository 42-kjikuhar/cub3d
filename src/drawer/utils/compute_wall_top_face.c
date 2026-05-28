/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_wall_top_face.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 19:45:52 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/28 21:14:20 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../drawer_private.h"

t_wall_top_face	compute_wall_top_face(\
	t_player const *player, t_hit const *hit, t_wall_side_face const *side)
{
	t_wall_top_face	top;
	t_dvec3			to_point;

	top.color = ((50 << 16) | (50 << 8) | (50));
	top.front_depth = side->top_depth;
	top.front = side->top;
	to_point = dvec3_sub(hit->back_pos, player->pos);
	compute_wall_point(player, to_point, &(top.back_depth), &(top.back));
	top.size = top.front - top.back + 1;
	top.draw_start = top.back;
	if (top.draw_start < 0)
		top.draw_start = 0;
	top.draw_end = top.front;
	if (top.draw_end >= W_HEIGHT)
		top.draw_end = W_HEIGHT - 1;
	return (top);
}
