/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 20:30:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/27 08:49:18 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_PRIVATE_H
# define PLAYER_PRIVATE_H

# include "types.h"

t_dvec3	calc_camera_right(t_dvec3 dir);
t_dvec3	calc_camera_up(t_dvec3 right, t_dvec3 dir);
void	move_player_forward(t_map const *map, t_player *player);
void	move_player_left(t_map const *map, t_player *player);
void	move_player_back(t_map const *map, t_player *player);
void	move_player_right(t_map const *map, t_player *player);
bool	is_colliding_with_wall(t_map const *map, t_dvec3 pos);
void	rotate_player_left(t_player *player);
void	rotate_player_right(t_player *player);
void	rotate_player_up(t_player *player);
void	rotate_player_down(t_player *player);

#endif
