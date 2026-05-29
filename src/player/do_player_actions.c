/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_player_actions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 08:35:54 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/29 13:41:00 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./player_private.h"

static void	move_player_actions(void);
static void	rotate_player_actions(void);

void	do_player_actions(void)
{
	move_player_actions();
	rotate_player_actions();
}

static void	move_player_actions(void)
{
	uint16_t const	action = player()->action_flag;

	if ((action & MOVE_FORWARD) && !(action & MOVE_BACK))
	{
		move_player_forward();
	}
	else if ((action & MOVE_BACK) && !(action & MOVE_FORWARD))
	{
		move_player_back();
	}
	if ((action & MOVE_LEFT) && !(action & MOVE_RIGHT))
	{
		move_player_left();
	}
	else if ((action & MOVE_RIGHT) && !(action & MOVE_LEFT))
	{
		move_player_right();
	}
}

static void	rotate_player_actions(void)
{
	uint16_t const	action = player()->action_flag;

	if ((action & ROTATE_UP) && !(action & ROTATE_DOWN))
	{
		rotate_player_up();
	}
	else if ((action & ROTATE_DOWN) && !(action & ROTATE_UP))
	{
		rotate_player_down();
	}
	if ((action & ROTATE_LEFT) && !(action & ROTATE_RIGHT))
	{
		rotate_player_left();
	}
	else if ((action & ROTATE_RIGHT) && !(action & ROTATE_LEFT))
	{
		rotate_player_right();
	}
}
