/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:38:56 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/30 12:49:32 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	g_colors[COLOR_COUNT];

int	color(enum e_color_id id)
{
	return (g_colors[id]);
}

void	set_color(enum e_color_id id, int rgb)
{
	g_colors[id] = rgb;
}

