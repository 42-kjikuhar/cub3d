/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 13:08:17 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/28 21:08:40 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./drawer_private.h"

t_wall	compute_wall(t_mlx *mlx, t_player const *player, t_hit const *hit)
{
	t_wall	wall;

	wall.side = compute_wall_side_face(mlx, player, hit);
	wall.top = compute_wall_top_face(player, hit, &(wall.side));
	return (wall);
}
