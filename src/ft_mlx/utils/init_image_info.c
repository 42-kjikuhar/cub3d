/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:16:34 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/22 16:17:11 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_image_info(t_img *img, int width, int height)
{
	img->img_ptr = NULL;
	img->width = width;
	img->height = height;
	img->pixel = NULL;
	img->bits_per_pixel = COLOR_BIT_SIZE;
	img->line_size = width;
	img->endian = LITTLE_ENDIAN;
}
