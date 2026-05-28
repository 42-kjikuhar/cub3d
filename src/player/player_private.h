/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 20:30:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/29 02:51:04 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_PRIVATE_H
# define PLAYER_PRIVATE_H

# include "types.h"

void	move_player_forward(t_player *player);
void	move_player_left(t_player *player);
void	move_player_back(t_player *player);
void	move_player_right(t_player *player);
bool	is_colliding_with_wall(t_dvec3 pos);
void	rotate_player_left(t_player *player);
void	rotate_player_right(t_player *player);
void	rotate_player_up(t_player *player);
void	rotate_player_down(t_player *player);
t_dvec3	calc_player_right(t_dvec3 dir);
t_dvec3	calc_player_up(t_dvec3 right, t_dvec3 dir);

#endif
