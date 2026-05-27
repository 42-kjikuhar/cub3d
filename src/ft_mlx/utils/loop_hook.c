/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:49:56 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/27 10:36:53 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	loop_hook(void *param)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)param;
	handle_player_actions(&(cub3d->map), &(cub3d->player));
	drawer(cub3d);
	if (DEBUG)
		mlx_loop_end(cub3d->mlx.mlx_ptr);
	return (0);
}
