/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 13:08:17 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/29 02:41:57 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./drawer_private.h"

t_wall	compute_wall(t_mlx *mlx, t_hit const *hit)
{
	t_wall	wall;

	wall.side = compute_wall_side_face(mlx, hit);
	wall.top = compute_wall_top_face(hit, &(wall.side));
	return (wall);
}
