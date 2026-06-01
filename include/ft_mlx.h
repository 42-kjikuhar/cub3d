/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 22:50:14 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/06/01 23:32:28 by stanaka2         ###   ########.fr       */
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
	IMG_WINDOW,
	IMG_NORTH_WALL,
	IMG_SOUTH_WALL,
	IMG_WEST_WALL,
	IMG_EAST_WALL,
	IMG_FLOOR,
	IMG_CEILING,
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

bool			create_mlx_connection(void);
bool			create_window(int width, int height, char *title);
bool			create_image(enum e_image_id id, int width, int height);
bool			create_image_from_xpm(\
					char *xpm, enum e_image_id id, int width, int height);
void			*get_mlx_ptr(void);
void			*get_win_ptr(void);
t_image			*get_image(enum e_image_id id);
void			ft_mlx_hooks(void);
void			ft_mlx_destroy(void);
unsigned int	*get_pixel_addr(t_image *image, int const x, int const y);

#endif
