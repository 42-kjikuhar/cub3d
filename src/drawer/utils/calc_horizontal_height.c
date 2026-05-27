/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_horizontal_height.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 11:52:52 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/27 11:55:49 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	calc_horizontal_height(t_player const *player)
{
	double	cos_p;

	cos_p = sqrt(player->dir.x * player->dir.x + player->dir.y * player->dir.y);
	if (player->dir.z >= player->screen_half_height * cos_p)
		return (W_HEIGHT + 0.5);
	else if (player->dir.z <= -player->screen_half_height * cos_p)
		return (-0.5);
	return ((W_HEIGHT / 2) \
		+ (W_HEIGHT / 2) * player->dir.z / (cos_p * player->screen_half_height));
}

double	calc_horizontal_height(t_player const *player)
{
	if (player->dir.z >= player->screen_half_height)
		return (W_HEIGHT + 0.5);
	else if (player->dir.z <= -player->screen_half_height)
		return (-0.5);
	return ((W_HEIGHT / 2) \
	+ (W_HEIGHT / 2) * player->dir.z / player->screen_half_height);
}
