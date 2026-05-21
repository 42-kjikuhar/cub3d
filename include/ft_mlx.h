/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 22:50:14 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/21 23:11:43 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
# define FT_MLX_H

# include <stdbool.h>
# include "types.h"

struct s_img
{
	void		*img_ptr;
	int			width;
	int			height;
	char		*pixel;
	int			*bits_per_pixel;
	int			size_line;
	int			endian;
};

struct s_assets
{
	t_img		north_wall;
	t_img		south_wall;
	t_img		west_wall;
	t_img		east_wall;
};

struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		win_img;
	t_assets	assets;
};

bool	ft_mlx_init(t_mlx *mlx, t_settings *settings);
void	ft_mlx_hooks(t_cub3d *cub3d);
void	ft_mlx_destroy(t_mlx *mlx);

/* utils */
int		expose_hook(void *param);
int		key_press_hook(int keycode, void *param);
int		key_release_hook(int keycode, void *param);
int		loop_hook(void *param);

#endif
