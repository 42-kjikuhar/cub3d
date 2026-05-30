/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 20:22:19 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/30 13:19:40 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include <stdint.h>

# include "types.h"
# include "vector/dvec3.h"

// "PLAYER_OFFSET must be less than 0.5."
# define PLAYER_OFFSET 0.05
// "MOVE_SPEED must be less than (PLAYER_OFFSET * 2)."
# define MOVE_SPEED 0.025

enum e_action_flag
{
	MOVE_FORWARD = (1 << 0),
	MOVE_LEFT = (1 << 1),
	MOVE_BACK = (1 << 2),
	MOVE_RIGHT = (1 << 3),
	ROTATE_UP = (1 << 4),
	ROTATE_LEFT = (1 << 5),
	ROTATE_DOWN = (1 << 6),
	ROTATE_RIGHT = (1 << 7),
};

struct s_player
{
	t_dvec3		pos;
	t_dvec3		dir;
	t_dvec3		right;
	t_dvec3		up;
	uint16_t	action_flag;
};

void			init_player(t_map_player const *map_player);
t_player const	*get_player(void);
void			change_player_pos(t_dvec3 pos);
void			change_player_dir(t_dvec3 dir);
void			set_player_action(enum e_action_flag action);
void			unset_player_action(enum e_action_flag action);
void			do_player_actions(void);

#endif
