/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:38:56 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/31 22:04:25 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	g_colors[COLOR_COUNT];

int	get_color(enum e_color_id id)
{
	return (g_colors[id]);
}

void	set_color(enum e_color_id id, int color)
{
	g_colors[id] = color;
}
