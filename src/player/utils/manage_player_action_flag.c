/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_player_action_flag.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 13:13:03 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/30 13:24:17 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../player_private.h"

void	set_player_action(enum e_action_flag action)
{
	get_mutable_player()->action_flag |= action;
}

void	unset_player_action(enum e_action_flag action)
{
	get_mutable_player()->action_flag &= ~action;
}
