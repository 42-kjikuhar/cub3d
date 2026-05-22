/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 23:17:38 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/22 17:26:04 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_PRIVATE_H
# define FT_MLX_PRIVATE_H

#include <stdbool.h>

#include "types.h"

bool	create_connection(t_mlx *mlx);
bool	create_window_image(t_mlx *mlx);
bool	create_assets(t_mlx *mlx, t_settings *settings);
void	init_image_info(t_img *img, int width, int height);
bool	create_window(t_mlx *mlx);

#endif
