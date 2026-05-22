/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:50:19 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/22 17:41:53 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_release_hook(int keycode, void *param)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)param;
	(void)cub3d;
	(void)keycode;
	return (0);
}
