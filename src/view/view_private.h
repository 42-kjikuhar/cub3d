/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_private.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 00:17:04 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/29 02:57:08 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_PRIVATE_H
# define VIEW_PRIVATE_H

t_dvec3	calc_camera_right(t_dvec3 dir);
t_dvec3	calc_camera_up(t_dvec3 right, t_dvec3 dir);
void	set_screen_horizontal_pixel(void);

#endif
