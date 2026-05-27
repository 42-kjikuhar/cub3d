/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 22:37:06 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/27 22:41:39 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "types.h"
# include "cub3d.h"

struct s_player
{
	t_dvec3	pos;
	t_dvec3	dir;
	t_dvec3	plane;
};

#endif
