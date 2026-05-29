/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:50:19 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/29 13:01:17 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_release_hook(int keycode, void *param)
{

	(void)param;
	if (keycode == XK_w)
		unset_player_action(MOVE_FORWARD);
	else if (keycode == XK_a)
		unset_player_action(MOVE_LEFT);
	else if (keycode == XK_s)
		unset_player_action(MOVE_BACK);
	else if (keycode == XK_d)
		unset_player_action(MOVE_RIGHT);
	else if (keycode == XK_Up)
		unset_player_action(ROTATE_UP);
	else if (keycode == XK_Left)
		unset_player_action(ROTATE_LEFT);
	else if (keycode == XK_Down)
		unset_player_action(ROTATE_DOWN);
	else if (keycode == XK_Right)
		unset_player_action(ROTATE_RIGHT);
	return (0);
}
