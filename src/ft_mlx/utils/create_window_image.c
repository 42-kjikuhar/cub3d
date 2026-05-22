/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window_image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:12:47 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/22 17:28:25 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../ft_mlx_private.h"

bool	create_window_image(t_mlx *mlx)
{
	init_image_info(&(mlx->win_img), W_WIDTH, W_HEIGHT);
	mlx->win_img.img_ptr = mlx_new_image(mlx->mlx_ptr, \
							mlx->win_img.width, mlx->win_img.height);
	if (mlx->win_img.img_ptr == NULL)
	{
		print_error(ERROR_MLX_IMAGE);
		return (false);
	}
	mlx->win_img.pixel = mlx_get_data_addr(\
					mlx->win_img.img_ptr, &(mlx->win_img.bits_per_pixel), \
					&(mlx->win_img.line_size), &(mlx->win_img.endian));
	if (mlx->win_img.pixel == NULL)
	{
		print_error(ERROR_MLX_IMAGE_DATA);
		return (false);
	}
	return (true);
}
