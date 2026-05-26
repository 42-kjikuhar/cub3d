/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 20:22:19 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/26 21:24:14 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
struct s_player
{
	t_dvec3	pos;
	t_dvec3	dir;
	t_dvec3	right;
	t_dvec3	up;
	double	aspect_ratio;
	double	screen_half_width;
	double	screen_half_height;
};

void	init_player(t_player *player, t_map const *map);

#endif
