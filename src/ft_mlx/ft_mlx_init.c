/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 23:10:23 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/21 23:11:05 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

bool	ft_mlx_init(t_mlx *mlx, t_settings *settings)
{
	if (!create_connection(mlx) \
	|| !create_window_image(mlx) \
	|| !create_assets(mlx, settings) \
	|| !create_window(mlx))
	{
		ft_mlx_destroy(mlx);
		return (false);
	}
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	return (true);
}
