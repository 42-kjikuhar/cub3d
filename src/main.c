/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 13:25:52 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/30 14:06:25 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char const *argv[])
{
	if (!vaildate_argument(argc, argv))
		return (EXIT_FAILURE);
	if (!create_mlx_connection())
		return (EXIT_FAILURE);
	if (!parse_file(argv[1]))
	{
		ft_mlx_destroy();
		return (EXIT_FAILURE);
	}
	init_player(get_map_player());
	init_view(FOV, get_player()->pos, get_player()->dir);
	if (!create_image(IMG_WINDOW, W_WIDTH, W_HEIGHT) \
		|| !create_window(W_WIDTH, W_HEIGHT, W_TITLE))
	{
		cleanup_map();
		ft_mlx_destroy();
		return (EXIT_FAILURE);
	}
	mlx_clear_window(get_mlx_ptr(), get_win_ptr());
	ft_mlx_hooks();
	mlx_loop(get_mlx_ptr());
	cleanup_map();
	ft_mlx_destroy();
	return (EXIT_SUCCESS);
}
