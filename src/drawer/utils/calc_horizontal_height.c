/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_horizontal_height.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 11:52:52 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/25 12:01:37 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	calc_horizontal_height(t_player const *player)
{
	double	aspect_ratio;
	double	vertical_fov;

	if (player->dir.z == 1.0)
		return (W_HEIGHT + 0.5);
	else if (player->dir.z == -1.0)
		return (-0.5);

	aspect_ratio = (double)W_WIDTH / W_HEIGHT;
	vertical_fov = atan(tan((FOV / 2) * DEG_TO_RAD) / aspect_ratio);
	return ((W_HEIGHT / 2) \
		- (W_HEIGHT / 2) * player->dir.z / tan(vertical_fov));
}
