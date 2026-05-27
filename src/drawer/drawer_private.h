/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 22:53:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/27 21:33:17 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWER_PRIVATE_H
# define DRAWER_PRIVATE_H

# include <stdint.h>

# include "types.h"
# include "cub3d.h"

# define WALL_HEIGHT 1

typedef struct s_ray
{
	t_dvec3	origin;
	t_dvec3	vector;
	double	length;
	double	delta_dist_x;
	double	delta_dist_y;
	t_ivec2	cell;
	t_ivec2	cell_step;
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

typedef struct s_hit
{
	double	perp_wall_dist;
	uint8_t	hit_side;
	double	pos_x;
	double	pos_y;
}	t_hit;

typedef struct s_wall_side_face
{
	t_img	*texture;
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

void				floor_drawer(t_cub3d *cub3d);
void				sky_drawer(t_cub3d *cub3d);
void				wall_drawer(t_cub3d *cub3d);
double				calc_horizontal_screen_height(t_player const *player);
t_ray				init_ray(t_player const *player, int win_x);
t_hit				dda_algorithm(t_map const *map, t_ray *ray);
t_wall				compute_wall(t_mlx *mlx, t_player const *player, \
						t_ray const *ray, t_hit const *hit);
t_wall_side_face	compute_wall_side_face(t_mlx *mlx, t_player const *player, \
						t_ray const *ray, t_hit const *hit);
t_wall_top_face		compute_wall_top_face(t_player const *player, \
					t_ray const *ray, t_wall_side_face *side);
void				compute_wall_point(t_player const *player, \
				t_dvec3 to_point, double *point_depth, int *point_screen_height);
void				clear_depth_buffer(void);
bool				try_depth_buffer(double depth, int x, int y);

#endif
