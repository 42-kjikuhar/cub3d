/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:49:56 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/27 23:17:39 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	floor_drawer(t_mlx *mlx, t_settings const *settings)
{
	int const	horizontal_height = (int)floor((double)W_HEIGHT / 2);
	int const	floor_color = mlx_get_color_value(mlx->mlx_ptr, \
		settings->floor_color);
	int			x;
	int			y;

	y = horizontal_height;
	while (y < W_HEIGHT)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			*get_pixel_addr(&(mlx->win_img), x, y) = floor_color;
			++x;
		}
		++y;
	}

}

void	ceiling_drawer(t_mlx *mlx, t_settings const *settings)
{
	int const	horizontal_height = (int)floor((double)W_HEIGHT / 2);
	int const	ceiling_color = mlx_get_color_value(mlx->mlx_ptr, \
		settings->ceiling_color);
	int			x;
	int			y;

	y = 0;
	while (y < horizontal_height)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			*get_pixel_addr(&(mlx->win_img), x, y) = ceiling_color;
			++x;
		}
		++y;
	}
}

void	drawer(t_cub3d *cub3d)
{
	floor_drawer(&(cub3d->mlx), &(cub3d->settings));
	ceiling_drawer(&(cub3d->mlx), &(cub3d->settings));
	mlx_put_image_to_window(cub3d->mlx.mlx_ptr, cub3d->mlx.win_ptr, \
		cub3d->mlx.win_img.img_ptr, 0, 0);
}

int	loop_hook(void *param)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)param;
	if (DEBUG)
		mlx_loop_end(cub3d->mlx.mlx_ptr);
	drawer(cub3d);
	return (0);
}
