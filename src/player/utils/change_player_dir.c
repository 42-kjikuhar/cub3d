/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_player_dir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 13:15:21 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/30 13:23:40 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../player_private.h"

void	change_player_dir(t_dvec3 dir)
{
	t_player	*player;

	player = get_mutable_player();
	player->dir = dir;
	player->right = calc_player_right(player->dir);
	player->up = calc_player_up(player->right, player->dir);
}
