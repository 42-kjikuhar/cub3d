/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_player_dir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 13:15:21 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/29 13:41:09 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../player_private.h"

void	change_player_dir(t_dvec3 dir)
{
	t_player	*p;

	p = mutable_player();
	p->dir = dir;
	p->right = calc_player_right(p->dir);
	p->up = calc_player_up(p->right, p->dir);
}
