/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 20:30:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/26 20:44:38 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_PRIVATE_H
# define PLAYER_PRIVATE_H

# include "types.h"

t_dvec3	calc_camera_right(t_dvec3 dir);
t_dvec3	calc_camera_up(t_dvec3 right, t_dvec3 dir);

#endif
