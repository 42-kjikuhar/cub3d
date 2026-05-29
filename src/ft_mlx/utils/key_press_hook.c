/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:50:32 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/29 11:39:12 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press_hook(int keycode, void *param)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)param;
	if (keycode == XK_Escape)
		mlx_loop_end(cub3d->mlx.mlx_ptr);
	else if (keycode == XK_w)
		set_player_action(MOVE_FORWARD);
	else if (keycode == XK_a)
		set_player_action(MOVE_LEFT);
	else if (keycode == XK_s)
		set_player_action(MOVE_BACK);
	else if (keycode == XK_d)
		set_player_action(MOVE_RIGHT);
	else if (keycode == XK_Up)
		set_player_action(ROTATE_UP);
	else if (keycode == XK_Left)
		set_player_action(ROTATE_LEFT);
	else if (keycode == XK_Down)
		set_player_action(ROTATE_DOWN);
	else if (keycode == XK_Right)
		set_player_action(ROTATE_RIGHT);
	return (0);
}
