/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 00:09:38 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/29 02:57:26 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_H
# define VIEW_H

# include "types.h"
# include "vector/dvec3.h"

# define FOV 66

struct s_camera
{
	t_dvec3	pos;
	t_dvec3	dir;
	t_dvec3	right;
	t_dvec3	up;
};

struct s_screen
{
	double	aspect_ratio;
	double	half_height;
	double	half_width;
	double	horizontal_pixel;
};

t_camera const	*camera(void);
void			set_camera(t_dvec3 pos, t_dvec3 dir);
void			set_camera_lookat(t_dvec3 look_from, t_dvec3 look_at);
void			change_camera_pos(t_dvec3 pos);
void			change_camera_dir(t_dvec3 dir);
t_screen const	*screen(void);
void			set_screen(double horizontal_fov);

#endif
