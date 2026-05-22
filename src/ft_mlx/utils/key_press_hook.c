/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:50:32 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/22 17:53:03 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press_hook(int keycode, void *param)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)param;
	if (keycode == XK_Escape)
		mlx_loop_end(cub3d->mlx.mlx_ptr);
	return (0);
}
