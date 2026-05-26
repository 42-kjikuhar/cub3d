/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 22:53:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/26 16:39:59 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWER_PRIVATE_H
# define DRAWER_PRIVATE_H

# include <stdint.h>

# include "types.h"
# include "cub3d.h"

typedef struct	s_ray
{
	t_dvec3	origin;
	t_dvec3	vector;
	double	length;
	double	delta_dist_x
	double	delta_dist_y;
	t_ivec2	cell;
	t_ivec2	step;
	double	delta_height_x;
	double	delta_height_y;
	double	wall_dist_x;
	double	wall_dist_y;
}	t_ray;

enum e_hit_side
{
	NO_HIT = 0,
	NORTH_SIDE = (1 << 0),
	SOUTH_SIDE = (1 << 1),
	WEST_SIDE = (1 << 2),
	EAST_SIDE = (1 << 3),
	TOP_SIDE = (1 << 4),
	BOTTOM_SIDE = (1 << 5),
};

typedef struct	s_hit
{
	double	perp_wall_dist;
	uint8_t	hit_side;
	double	pos_x;
	double	pos_y;
}	t_hit;

typedef struct s_wall
{
	t_img	*texture;
	t_ivec2	texture_pixel;
	int		top;
	int		bottom;
}	t_wall;

double	calc_horizontal_height(t_player const *player);

#endif
