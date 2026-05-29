/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_addr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 17:55:08 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/29 17:02:20 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	*get_pixel_addr(t_image *image, int x, int y)
{
	return ((unsigned int *)(image->pixel \
				+ y * image->line_size + x * image->bits_per_pixel / 8));
}
