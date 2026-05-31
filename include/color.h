/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:48:04 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/31 22:27:31 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

enum e_color_id
{
	COLOR_FLOOR,
	COLOR_CEILING,
	COLOR_COUNT,
};

int		get_color(enum e_color_id id);
void	set_color(enum e_color_id id, int color);

#endif
