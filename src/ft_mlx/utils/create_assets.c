/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_assets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:12:43 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/22 17:23:53 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../ft_mlx_private.h"

static bool	create_xpm_image(t_mlx *mlx, t_img *img, char *xpm);

bool	create_assets(t_mlx *mlx, t_settings *settings)
{
	if (!create_xpm_image(mlx, \
			&(mlx->assets.north_wall), settings->north_texture) \
		|| !create_xpm_image(mlx, \
			&(mlx->assets.south_wall), settings->south_texture) \
		|| !create_xpm_image(mlx, \
			&(mlx->assets.west_wall), settings->west_texture) \
		|| !create_xpm_image(mlx, \
			&(mlx->assets.east_wall), settings->east_texture))
	{
		return (false);
	}
	return (true);
}

static bool	create_xpm_image(t_mlx *mlx, t_img *img, char *xpm)
{
	init_image_info(img, TEXTURE_SIZE, TEXTURE_SIZE);
	img->img_ptr = mlx_xpm_file_to_image(\
				mlx->mlx_ptr, xpm, &(img->width), &(img->height));
	if (img->img_ptr == NULL)
	{
		print_error(ERROR_MLX_TEXTURE_LOAD);
		return (false);
	}
	img->pixel = mlx_get_data_addr(img->img_ptr, \
					&(img->bits_per_pixel), &(img->line_size), &(img->endian));
	if (img->pixel == NULL)
	{
		print_error(ERROR_MLX_IMAGE_DATA);
		return (false);
	}
	return (true);
}
