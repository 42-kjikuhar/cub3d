/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 22:53:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/31 22:05:24 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWER_PRIVATE_H
# define DRAWER_PRIVATE_H

# include <stdint.h>

# include "types.h"
# include "cub3d.h"

# define WALL_HEIGHT 1

typedef struct s_dda
{
	t_dvec3	origin;
	t_dvec3	ray;
	double	screen_dist;
	double	delta_dist_x;
	double	delta_dist_y;
	double	dist_x;
	double	dist_y;
	t_ivec2	cell;
	t_ivec2	cell_step;
	double	delta_height_x;
	double	delta_height_y;
}	t_dda;

enum e_hit_side
{
	NO_HIT,
	NORTH_SIDE,
	SOUTH_SIDE,
	WEST_SIDE,
	EAST_SIDE,
};

typedef struct s_hit
{
	enum e_hit_side	hit_side;
	t_dvec3			front_pos;
	t_dvec3			back_pos;
}	t_hit;

typedef struct s_wall_side_face
{
	t_image	*texture;
	t_ivec2	texture_pixel;
	int		top;
	int		bottom;
	int		size;
	int		draw_start;
	int		draw_end;
	double	top_depth;
	double	bottom_depth;
}	t_wall_side_face;

typedef struct s_wall_top_face
{
	int		color;
	int		front;
	int		back;
	int		size;
	int		draw_start;
	int		draw_end;
	double	front_depth;
	double	back_depth;
}	t_wall_top_face;

typedef struct s_wall
{
	t_wall_side_face	side;
	t_wall_top_face		top;
}	t_wall;

void				floor_drawer(void);
void				ceiling_drawer(void);
void				wall_drawer(void);
t_dda				init_dda_info(int win_x);
t_hit				search_hitting_wall(t_dda *dda);
t_wall				compute_wall(t_hit const *hit);
t_wall_side_face	compute_wall_side_face(t_hit const *hit);
t_wall_top_face		compute_wall_top_face(\
						t_hit const *hit, t_wall_side_face const *side);
void				compute_wall_point(\
			t_dvec3 to_point, double *point_depth, int *point_screen_height);
void				clear_depth_buffer(void);
bool				try_depth_buffer(double depth, int x, int y);

#endif
