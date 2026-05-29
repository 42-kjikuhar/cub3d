/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 11:02:01 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/29 13:15:03 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./player_private.h"

static t_player	g_player;

t_player const	*player(void)
{
	return (&g_player);
}

t_player	*mutable_player(void)
{
	return (&g_player);
}
