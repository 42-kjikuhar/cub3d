/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:49:56 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/30 13:39:08 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	loop_hook(void *param)
{
	(void)param;
	do_player_actions();
	drawer();
	if (DEBUG)
		mlx_loop_end(get_mlx_ptr());
	return (0);
}
