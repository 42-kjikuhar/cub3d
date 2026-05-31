/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 17:32:52 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/31 22:08:15 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_PRIVATE_H
# define FT_MLX_PRIVATE_H

# include <stdbool.h>

# include "types.h"

void	cleanup_mlx_connection(void);
void	cleanup_window(void);
void	cleanup_images(void);
void	init_image_info(t_image *image, int width, int height);
int		expose_hook(void *param);
int		key_press_hook(int keycode, void *param);
int		key_release_hook(int keycode, void *param);
int		loop_hook(void *param);

#endif
