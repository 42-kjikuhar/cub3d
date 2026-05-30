/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 20:30:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/30 13:21:57 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_PRIVATE_H
# define PLAYER_PRIVATE_H

# include "types.h"

t_player	*get_mutable_player(void);
void		change_player_pos(t_dvec3 pos);
void		change_player_dir(t_dvec3 dir);
void		move_player_forward(void);
void		move_player_left(void);
void		move_player_back(void);
void		move_player_right(void);
bool		is_colliding_with_wall(t_dvec3 pos);
void		rotate_player_left(void);
void		rotate_player_right(void);
void		rotate_player_up(void);
void		rotate_player_down(void);
t_dvec3		calc_player_right(t_dvec3 dir);
t_dvec3		calc_player_up(t_dvec3 right, t_dvec3 dir);

#endif
