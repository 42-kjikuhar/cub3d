/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:31:08 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/22 16:48:48 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ft_mlx_private.h"

void	ft_mlx_hooks(t_cub3d *cub3d)
{
	mlx_expose_hook(cub3d->mlx.win_ptr, expose_hook, (void *)cub3d);
	mlx_hook(cub3d->mlx.win_ptr, ClientMessage, NoEventMask, \
		mlx_loop_end, cub3d->mlx.mlx_ptr);
	mlx_hook(cub3d->mlx.win_ptr, KeyPress, KeyPressMask, \
		key_press_hook, (void *)cub3d);
	mlx_key_hook(cub3d->mlx.win_ptr, key_release_hook, (void *)cub3d);
	mlx_loop_hook(cub3d->mlx.mlx_ptr, loop_hook, (void *)cub3d);
}
