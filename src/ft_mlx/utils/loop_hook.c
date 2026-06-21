/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:49:56 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/21 18:49:06 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	floor_drawer(t_mlx *mlx, t_settings const *settings)
{
	int const	horizontal_height = (int)floor((double)W_HEIGHT / 2);
	int const	floor_color = mlx_get_color_value(mlx->mlx_ptr, \
		settings->floor_color);
	int			x;
	int			y;

	y = horizontal_height;
	while (y < W_HEIGHT)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			*get_pixel_addr(&(mlx->win_img), x, y) = floor_color;
			++x;
		}
		++y;
	}

}

void	ceiling_drawer(t_mlx *mlx, t_settings const *settings)
{
	int const	horizontal_height = (int)floor((double)W_HEIGHT / 2);
	int const	ceiling_color = mlx_get_color_value(mlx->mlx_ptr, \
		settings->ceiling_color);
	int			x;
	int			y;

	y = 0;
	while (y < horizontal_height)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			*get_pixel_addr(&(mlx->win_img), x, y) = ceiling_color;
			++x;
		}
		++y;
	}
}

typedef struct s_ray
{
	t_dvec3		vector;
	t_dvec3		origin;
	double		length;
}				t_ray;

enum e_hit_side
{
	NORTH_SIDE,
	SOUTH_SIDE,
	WEST_SIDE,
	EAST_SIDE
};

static double	normalize_window_x(int window_x)
{
	return (((double)window_x - W_WIDTH / 2) / W_WIDTH * 2);
}

t_ray	create_ray(t_player *player, int window_x)
{
	t_ray			ray;
	double const	t = (double)normalize_window_x(window_x);

	ray.origin = player->pos;
	ray.vector = dvec3_add(player->dir, dvec3_scale(t, player->plane));
	ray.length = dvec3_length(dvec3(ray.vector.x, ray.vector.y, 0));
	return (ray);
}

typedef struct s_dda
{
	double		dist_x;
	double		dist_y;
	double		delta_x;
	double		delta_y;
	t_ivec2		cell;
	t_ivec2		cell_step;
}				t_dda;

t_dda	init_dda(t_ray *ray)
{
	t_dda	dda;

	dda.delta_x = fabs(ray->length / ray->vector.x);
	dda.delta_y = fabs(ray->length / ray->vector.y);
	if (ray->vector.x > 0)
		dda.dist_x = dda.delta_x * (ceil(ray->origin.x) - ray->origin.x);
	else
		dda.dist_x = dda.delta_x * (ray->origin.x - floor(ray->origin.x));
	if (ray->vector.y > 0)
		dda.dist_y = dda.delta_y * (ceil(ray->origin.y) - ray->origin.y);
	else
		dda.dist_y = dda.delta_y * (ray->origin.y - floor(ray->origin.y));
	dda.cell = ivec2((int)(ray->origin.x), (int)(ray->origin.y));
	if (ray->vector.x > 0)
		dda.cell_step.x = 1;
	else
		dda.cell_step.x = -1;
	if (ray->vector.y > 0)
		dda.cell_step.y = 1;
	else
		dda.cell_step.y = -1;
	return (dda);
}

typedef struct s_hit
{
	t_dvec3			pos;
	double			distance;
	enum e_hit_side	side;
}				t_hit;

t_hit	calculate_hit(t_ray *ray, t_dda *dda)
{
	t_hit	hit;

	if (dda->dist_x < dda->dist_y)
	{
			hit.pos = dvec3_add(ray->origin, \
				dvec3_scale(dda->dist_x / ray->length, ray->vector));
		hit.distance = dda->dist_x / ray->length;
		if (ray->vector.x > 0)
			hit.side = WEST_SIDE;
		else
			hit.side = EAST_SIDE;
	}
	else
	{
		hit.pos = dvec3_add(ray->origin, \
			dvec3_scale(dda->dist_y / ray->length, ray->vector));
		hit.distance = dda->dist_y / ray->length;
		if (ray->vector.y > 0)
			hit.side = NORTH_SIDE;
		else
			hit.side = SOUTH_SIDE;
	}
	return (hit);
}

t_hit	hit_wall(t_map *map, t_ray *ray)
{
	t_dda	dda;

	dda = init_dda(ray);
	while (true)
	{
		if (dda.dist_x < dda.dist_y)
			dda.cell.x += dda.cell_step.x;
		else
			dda.cell.y += dda.cell_step.y;
		if (map->data[dda.cell.y][dda.cell.x] == MAP_WALL)
			return (calculate_hit(ray, &dda));
		if (dda.dist_x < dda.dist_y)
			dda.dist_x += dda.delta_x;
		else
			dda.dist_y += dda.delta_y;
	}
}

typedef struct s_wall
{
	t_img		*texture;
	t_ivec2		texture_pixel;
	int			size;
	int			top;
	int			bottom;
}				t_wall;

t_img	*decide_hit_texture(t_mlx* mlx, enum e_hit_side	side)
{
	if (side == NORTH_SIDE)
		return (&(mlx->assets.north_wall));
	else if (side == SOUTH_SIDE)
		return (&(mlx->assets.south_wall));
	else if (side == EAST_SIDE)
		return (&(mlx->assets.east_wall));
	else if (side == WEST_SIDE)
		return (&(mlx->assets.west_wall));
	return (NULL);
}

t_ivec2	calculate_texture_pixel(t_hit *hit)
{
	if (hit->side == NORTH_SIDE)
		return (ivec2((int)((ceil(hit->pos.x) - hit->pos.x) * TEXTURE_SIZE), 0));
	else if (hit->side == SOUTH_SIDE)
		return (ivec2((int)((hit->pos.x - floor(hit->pos.x)) * TEXTURE_SIZE), 0));
	else if (hit->side == EAST_SIDE)
		return (ivec2((int)((hit->pos.y - floor(hit->pos.y)) * TEXTURE_SIZE), 0));
	else if (hit->side == WEST_SIDE)
		return (ivec2((int)((ceil(hit->pos.y) - hit->pos.y) * TEXTURE_SIZE), 0));
	return (ivec2(0, 0));
}

static int	calculate_size(t_hit *hit, t_player *player)
{
	double	ratio;
	int	wall_screen_size;

	ratio = (1 / player->screen_size.y) * (1 / hit->distance);
	wall_screen_size = (int)round(ratio * W_HEIGHT);
	return (wall_screen_size);
}

t_wall	calculate_wall(t_mlx *mlx, t_hit *hit, t_player *player)
{
	t_wall	wall;

	wall.texture = decide_hit_texture(mlx, hit->side);
	wall.texture_pixel = calculate_texture_pixel(hit);
	wall.size = calculate_size(hit, player);
	wall.top = W_HEIGHT / 2 - wall.size / 2;
	wall.bottom = W_HEIGHT / 2 + wall.size / 2;
	return (wall);
}


void	draw_wall(t_mlx *mlx, t_wall *wall, int window_x)
{
	int const	start = (int)fmax((double)wall->top, 0);
	int const	end = (int)fmin(wall->bottom, W_HEIGHT - 1);
	int			y;
	double		texture_y;
	double		step;

	y = start;
	step = TEXTURE_SIZE / (double)wall->size;
	texture_y = (start - wall->top) * step;
	while (y <= end)
	{
		wall->texture_pixel.y = (int)round(texture_y);
		*get_pixel_addr(&(mlx->win_img), window_x, y) = *get_pixel_addr(\
			wall->texture, wall->texture_pixel.x, wall->texture_pixel.y);
		++y;
		texture_y += step;
	}

}

void	wall_drawer(t_mlx *mlx, t_map *map, t_player *player)
{
	int			window_x;
	t_ray		ray;
	t_hit		hit;
	t_wall		wall;

	window_x = 0;
	while (window_x < W_WIDTH)
	{
		ray = create_ray(player, window_x);
		hit = hit_wall(map, &ray);
		wall = calculate_wall(mlx, &hit, player);
		draw_wall(mlx, &wall, window_x);
		++window_x;
	}
}

void	drawer(t_cub3d *cub3d)
{
	floor_drawer(&(cub3d->mlx), &(cub3d->settings));
	ceiling_drawer(&(cub3d->mlx), &(cub3d->settings));
	wall_drawer(&(cub3d->mlx), &(cub3d->map), &(cub3d->player));
	mlx_put_image_to_window(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr, \
		cub3d->mlx.win_img.img_ptr, 0, 0);
}

int	loop_hook(void *param)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)param;
	if (DEBUG)
		mlx_loop_end(cub3d->mlx.mlx_ptr);
	drawer(cub3d);
	return (0);
}
