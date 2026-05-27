/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 22:37:06 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/27 23:13:40 by kjikuhar         ###   ########.fr       */
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
};

void	init_player(t_player *player, t_map const *map);

#endif
