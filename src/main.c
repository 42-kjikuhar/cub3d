/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 13:25:52 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/30 13:19:59 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char const *argv[])
{
	t_settings settings;

	if (!vaildate_argument(argc, argv))
		return (EXIT_FAILURE);
	ft_bzero(&settings, sizeof(t_settings));
	if (!parse_file(argv[1], &(settings)))
		return (EXIT_FAILURE);
	init_player(get_map_player());
	init_view(FOV, get_player()->pos, get_player()->dir);
	if (!ft_mlx_init(&settings))
	{
		cleanup_settings(&settings);
		cleanup_map();
		return (EXIT_FAILURE);
	}
	cleanup_settings(&settings);
	ft_mlx_hooks();
	mlx_loop(get_mlx_ptr());
	ft_mlx_destroy();
	cleanup_map();
	return (EXIT_SUCCESS);
}
