/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 13:25:52 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/27 22:42:49 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>


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
