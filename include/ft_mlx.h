/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 22:50:14 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/29 17:30:22 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
# define FT_MLX_H

# include <stdbool.h>
# include "types.h"

// # define W_WIDTH 1920
// # define W_HEIGHT 1080
# define W_WIDTH 1000
# define W_HEIGHT 600
# define W_TITLE "cub3D"

# define COLOR_BIT_SIZE 32
# define TEXTURE_SIZE 64

enum e_image_id
{
	WINDOW_IMG,
	NORTH_WALL_IMG,
	SOUTH_WALL_IMG,
	WEST_WALL_IMG,
	EAST_WALL_IMG,
	IMG_COUNT,
};
struct s_image
{
	void	*ptr;
	int		width;
	int		height;
	char	*pixel;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
};
void			*mlx_ptr(void);
void			*win_ptr(void);
t_image			*image(enum e_image_id id);
bool			ft_mlx_init(t_settings *settings);
void			ft_mlx_hooks(t_cub3d *cub3d);
void			ft_mlx_destroy(void);
unsigned int	*get_pixel_addr(t_image *image, int const x, int const y);

#endif
