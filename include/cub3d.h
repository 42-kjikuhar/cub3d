/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 13:27:17 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/20 23:27:47 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <limits.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>

# include "mlx.h"
# include "libft.h"

# include "vec2/ivec2.h"
# include "vec2/dvec2.h"

# define W_WIDTH 1920
# define W_HEIGHT 1080
# define W_TITLE "cub3D"
# define COLOR_BIT_SIZE 32
# define TEXTURE_SIZE 64

# define MAP_FLOOR '0'
# define MAP_WALL '1'
# define MAP_BLANK ' '
# define PLAYER_NORTH 'N'
# define PLAYER_SOUTH 'S'
# define PLAYER_WEST 'W'
# define PLAYER_EAST 'E'

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif
# define DEG_TO_RAD 0.01745329251994329547 // (M_PI / 180.0)
# define RAD_TO_DEG 57.29577951308232286465 // (180.0 / M_PI)
# define FOV 66

typedef struct s_settings
{
	int			flags;
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	int			floor_color;
	int			ceiling_color;
}				t_settings;

typedef struct s_map
{
	char			**data;
	int				x_size;
	int				y_size;
	t_ivec2			player_pos;
	char			player_dir;
}					t_map;

typedef struct s_player
{
	t_dvec2			pos;
	t_dvec2			dir;
	t_dvec2			plane;
}					t_player;

typedef struct s_img
{
	void		*img_ptr;
	int			width;
	int			height;
	char		*pixel;
	int			*bits_per_pixel;
	int			size_line;
	int			endian;
}				t_img;

typedef struct s_assets
{
	t_img		north_wall;
	t_img		south_wall;
	t_img		west_wall;
	t_img		east_wall;
}				t_assets;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		win_img;
	t_assets	assets;
}				t_mlx;

typedef struct s_cub3d
{
	t_settings	settings;
	t_map		map;
	t_player	player;
	t_mlx		mlx;
}				t_cub3d;

bool	parse_file(char const *filename, t_settings *settings, t_map *map);

/* cleanup */
void	cleanup_settings(t_settings *settings);
void	cleanup_map(t_map *map);

/* error */
void	print_error(char const *error_message);

/* parse_file */
bool	parse_file(char const *filename, t_settings *settings, t_map *map);

/* validate_argument*/
bool	vaildate_argument(int argc, char const *argv[]);

#endif
