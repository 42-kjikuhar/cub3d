/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:16:34 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/29 17:22:35 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_image_info(t_image *image, int width, int height)
{
	image->ptr = NULL;
	image->width = width;
	image->height = height;
	image->pixel = NULL;
	image->bits_per_pixel = COLOR_BIT_SIZE;
	image->line_size = width;
	image->endian = LITTLE_ENDIAN;
}
