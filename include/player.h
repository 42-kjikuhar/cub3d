/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 22:37:06 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/06/21 17:19:30 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "cub3d.h"
# include "types.h"

struct		s_player
{
	t_dvec3	pos;
	t_dvec3	dir;
	t_dvec3	plane;
	t_dvec3	screen_size;
};

void	init_player(t_player *player, t_map const *map);
void	init_screen_size(t_player *player);

#endif
