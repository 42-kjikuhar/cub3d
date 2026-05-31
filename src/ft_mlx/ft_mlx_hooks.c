/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:31:08 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/30 13:38:23 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./ft_mlx_private.h"

void	ft_mlx_hooks(void)
{
	mlx_expose_hook(get_win_ptr(), expose_hook, NULL);
	mlx_hook(get_win_ptr(), ClientMessage, NoEventMask, \
								mlx_loop_end, get_mlx_ptr());
	mlx_hook(get_win_ptr(), KeyPress, KeyPressMask, key_press_hook, NULL);
	mlx_key_hook(get_win_ptr(), key_release_hook, NULL);
	mlx_loop_hook(get_mlx_ptr(), loop_hook, NULL);
}
