/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 13:25:52 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/21 23:16:57 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	ft_mlx_destroy(t_mlx *mlx);

void	init_player(t_player *player, t_map const *map)
{
	double	plane_length;

	player->pos = dvec2(map->player_pos.x + 0.5, map->player_pos.y + 0.5);
	plane_length = tan(DEG_TO_RAD * FOV * 0.5);
	// plane_length = 1.0;
	if (map->player_dir == PLAYER_NORTH)
	{
		player->dir = dvec2(0, -1);
		player->plane = dvec2(plane_length, 0);
	}
	else if (map->player_dir == PLAYER_SOUTH)
	{
		player->dir = dvec2(0, 1);
		player->plane = dvec2(-plane_length, 0);
	}
	else if (map->player_dir == PLAYER_WEST)
	{
		player->dir = dvec2(-1, 0);
		player->plane = dvec2(0, plane_length);
	}
	else if (map->player_dir == PLAYER_EAST)
	{
		player->dir = dvec2(1, 0);
		player->plane = dvec2(0, -plane_length);
	}
}


bool	create_window_image(t_mlx *mlx)
{
	(void)mlx;
	return (true);
}

bool	create_assets(t_mlx *mlx, t_settings *settings)
{
	(void)mlx;
	(void)settings;
	return (true);
}

bool	create_window(t_mlx *mlx)
{
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, W_WIDTH, W_HEIGHT, W_TITLE);
	if (mlx->win_ptr == NULL)
	{
		print_error(ERROR_MLX_WINDOW);
		return (false);
	}
	return (true);
}



int		expose_hook(void *param)
{
	(void)param;
	return (0);
}

int		key_press_hook(int keycode, void *param)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)param;
	if (keycode ==  XK_Escape)
		mlx_loop_end(cub3d->mlx.mlx_ptr);
	return (0);
}

int		key_release_hook(int keycode, void *param)
{
	(void)keycode;
	(void)param;
	return (0);
}

int		loop_hook(void *param)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)param;
	if (DEBUG)
		mlx_loop_end(cub3d->mlx.mlx_ptr);
	return (0);
}

void	ft_mlx_hooks(t_cub3d *cub3d)
{
	mlx_expose_hook(cub3d->mlx.win_ptr, expose_hook, (void *)cub3d);
	mlx_hook(cub3d->mlx.win_ptr, ClientMessage, NoEventMask, \
		mlx_loop_end, cub3d->mlx.mlx_ptr);
	mlx_hook(cub3d->mlx.win_ptr, KeyPress, KeyPressMask, \
		key_press_hook, (void *)cub3d);
	mlx_key_hook(cub3d->mlx.win_ptr, key_release_hook, (void *)cub3d);
	mlx_loop_hook(cub3d->mlx.mlx_ptr, loop_hook, (void *)cub3d);
}

void	ft_mlx_destroy(t_mlx *mlx)
{
	if (mlx->assets.north_wall.img_ptr != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->assets.north_wall.img_ptr);
	if (mlx->assets.south_wall.img_ptr != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->assets.south_wall.img_ptr);
	if (mlx->assets.west_wall.img_ptr != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->assets.west_wall.img_ptr);
	if (mlx->assets.east_wall.img_ptr != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->assets.east_wall.img_ptr);
	if (mlx->win_img.img_ptr != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->win_img.img_ptr);
	if (mlx->win_ptr != NULL)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr != NULL)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
}

int	main(int argc, char const *argv[])
{
	t_cub3d	cub3d;

	if (!vaildate_argument(argc, argv))
		return (EXIT_FAILURE);
	ft_bzero(&cub3d, sizeof(t_cub3d));
	if (!parse_file(argv[1], &(cub3d.settings), &(cub3d.map)))
		return (EXIT_FAILURE);
	init_player(&(cub3d.player), &(cub3d.map));
	if (!ft_mlx_init(&(cub3d.mlx), &(cub3d.settings)))
	{
		cleanup_settings(&(cub3d.settings));
		cleanup_map(&(cub3d.map));
		return (EXIT_FAILURE);
	}
	ft_mlx_hooks(&cub3d);
	mlx_loop(cub3d.mlx.mlx_ptr);
	ft_mlx_destroy(&(cub3d.mlx));
	cleanup_settings(&(cub3d.settings));
	cleanup_map(&(cub3d.map));
	return (EXIT_SUCCESS);
}
