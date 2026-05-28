/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player_actions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 08:35:54 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/28 23:17:37 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./player_private.h"

static void	handle_move_player_actions(t_player *player);
static void	handle_rotate_player_actions(t_player *player);

void	handle_player_actions(t_player *player)
{
	handle_move_player_actions(player);
	handle_rotate_player_actions(player);
}

static void	handle_move_player_actions(t_player *player)
{
	if (player->action_flag & MOVE_FORWARD \
		&& !(player->action_flag & MOVE_BACK))
	{
		move_player_forward(player);
	}
	else if (player->action_flag & MOVE_BACK \
		&& !(player->action_flag & MOVE_FORWARD))
	{
		move_player_back(player);
	}
	if (player->action_flag & MOVE_LEFT \
		&& !(player->action_flag & MOVE_RIGHT))
	{
		move_player_left(player);
	}
	else if (player->action_flag & MOVE_RIGHT \
		&& !(player->action_flag & MOVE_LEFT))
	{
		move_player_right(player);
	}
}

static void	handle_rotate_player_actions(t_player *player)
{
	if (player->action_flag & ROTATE_UP \
		&& !(player->action_flag & ROTATE_DOWN))
	{
		rotate_player_up(player);
	}
	else if (player->action_flag & ROTATE_DOWN \
		&& !(player->action_flag & ROTATE_UP))
	{
		rotate_player_down(player);
	}
	if (player->action_flag & ROTATE_LEFT \
		&& !(player->action_flag & ROTATE_RIGHT))
	{
		rotate_player_left(player);
	}
	else if (player->action_flag & ROTATE_RIGHT \
		&& !(player->action_flag & ROTATE_LEFT))
	{
		rotate_player_right(player);
	}
}
