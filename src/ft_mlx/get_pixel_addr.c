/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_addr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 17:55:08 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/23 18:01:26 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

unsigned int	*get_pixel_addr(t_img *img, int const x, int const y)
{
	return ((unsigned int *)(img->pixel + \
		y * img->line_size + x  * img->bits_per_pixel / 8));
}
