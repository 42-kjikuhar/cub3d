/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 04:31:07 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/01 23:40:17 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./game_private.h"

bool	play_game(void)
{
	if (!load_default_game_info())
		return (false);
	init_player(get_map_player());
	init_view(FOV, get_player()->pos, get_player()->dir);
	if (!create_image(IMG_WINDOW, W_WIDTH, W_HEIGHT) \
		|| !create_window(W_WIDTH, W_HEIGHT, W_TITLE))
	{
		return (false);
	}
	mlx_clear_window(get_mlx_ptr(), get_win_ptr());
	ft_mlx_hooks();
	mlx_loop(get_mlx_ptr());
	return (true);
}
