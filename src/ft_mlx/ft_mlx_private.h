/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 17:32:52 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/29 17:32:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_PRIVATE_H
# define FT_MLX_PRIVATE_H

# include <stdbool.h>

# include "types.h"

bool	create_mlx_connection(void);
void	cleanup_mlx_connection(void);
bool	create_window(int width, int height, char *title);
void	cleanup_window(void);
bool	create_image(enum e_image_id id, int width, int height);
bool	create_image_from_xpm(\
			char *xpm, enum e_image_id id, int width, int height);
void	cleanup_images(void);
void	init_image_info(t_image *image, int width, int height);

int		expose_hook(void *param);
int		key_press_hook(int keycode, void *param);
int		key_release_hook(int keycode, void *param);
int		loop_hook(void *param);

#endif
