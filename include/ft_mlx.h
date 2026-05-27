/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 22:50:14 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/24 12:27:18 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
# define FT_MLX_H

# include <stdbool.h>
# include "types.h"

struct s_img
{
	void	*img_ptr;
	int		width;
	int		height;
	char	*pixel;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
};

struct s_assets
{
	t_img	north_wall;
	t_img	south_wall;
	t_img	west_wall;
	t_img	east_wall;
};

struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		win_img;
	t_assets	assets;
};

bool			ft_mlx_init(t_mlx *mlx, t_settings *settings);
void			ft_mlx_hooks(t_cub3d *cub3d);
void			ft_mlx_destroy(t_mlx *mlx);
unsigned int	*get_pixel_addr(t_img *img, int const x, int const y);

/* utils */
int				expose_hook(void *param);
int				key_press_hook(int keycode, void *param);
int				key_release_hook(int keycode, void *param);
int				loop_hook(void *param);

#endif
