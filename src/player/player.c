/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 11:02:01 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/30 13:22:09 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./player_private.h"

static t_player	g_player;

t_player const	*get_player(void)
{
	return (&g_player);
}

t_player	*get_mutable_player(void)
{
	return (&g_player);
}
