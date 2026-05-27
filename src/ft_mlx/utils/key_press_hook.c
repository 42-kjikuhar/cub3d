/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:50:32 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/27 10:36:35 by stanaka2         ###   ########.fr       */
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
		cub3d->player.action_flag |= MOVE_FORWARD;
	else if (keycode == XK_a)
		cub3d->player.action_flag |= MOVE_LEFT;
	else if (keycode == XK_s)
		cub3d->player.action_flag |= MOVE_BACK;
	else if (keycode == XK_d)
		cub3d->player.action_flag |= MOVE_RIGHT;
	else if (keycode == XK_Up)
		cub3d->player.action_flag |= ROTATE_UP;
	else if (keycode == XK_Left)
		cub3d->player.action_flag |= ROTATE_LEFT;
	else if (keycode == XK_Down)
		cub3d->player.action_flag |= ROTATE_DOWN;
	else if (keycode == XK_Right)
		cub3d->player.action_flag |= ROTATE_RIGHT;
	return (0);
}
