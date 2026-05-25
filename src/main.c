/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 13:25:52 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/25 11:31:52 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	init_player(t_player *player, t_map const *map)
{
	double	plane_length;

	player->pos = dvec3(map->player_pos.x + 0.5, map->player_pos.y + 0.5, 0.5);
	plane_length = tan(DEG_TO_RAD * FOV * 0.5);
	if (map->player_dir == PLAYER_NORTH)
	{
		player->dir = dvec3(0, -1, 0);
		player->plane = dvec3(plane_length, 0, 0);
	}
	else if (map->player_dir == PLAYER_SOUTH)
	{
		player->dir = dvec3(0, 1, 0);
		player->plane = dvec3(-plane_length, 0, 0);
	}
	else if (map->player_dir == PLAYER_WEST)
	{
		player->dir = dvec3(-1, 0, 0);
		player->plane = dvec3(0, plane_length, 0);
	}
	else if (map->player_dir == PLAYER_EAST)
	{
		player->dir = dvec3(1, 0, 0);
		player->plane = dvec3(0, -plane_length, 0);
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
