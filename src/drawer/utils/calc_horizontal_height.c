/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_horizontal_height.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 11:52:52 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/26 23:04:38 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double    calc_horizontal_height(t_player const *player)
{
	if (player->dir.z >= player->screen_half_height)
		return (W_HEIGHT + 0.5);
	else if (player->dir.z <= -player->screen_half_height)
		return (-0.5);
	return ((W_HEIGHT / 2) \
		+ (W_HEIGHT / 2) * player->dir.z / player->screen_half_height);
}
