/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:50:32 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/21 19:23:01 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	player_rotate_left(t_player *player)
{
	player->dir = dvec3_rotate(player->dir, dvec3(0, 0, 1), 1);
	player->plane = dvec3_rotate(player->plane, dvec3(0, 0, 1), 1);
}

static void	player_rotate_right(t_player *player)
{
	player->dir = dvec3_rotate(player->dir, dvec3(0, 0, 1), -1);
	player->plane = dvec3_rotate(player->plane, dvec3(0, 0, 1), -1);
}

int	key_press_hook(int keycode, void *param)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)param;
	if (keycode == XK_Escape)
		mlx_loop_end(cub3d->mlx.mlx_ptr);
	if (keycode == XK_Left)
		player_rotate_left(&(cub3d->player));
	if (keycode == XK_Right)
		player_rotate_right(&(cub3d->player));
	return (0);
}
